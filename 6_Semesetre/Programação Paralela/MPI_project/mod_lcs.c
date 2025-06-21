#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <math.h>
#include <omp.h>

#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
#define min( a,b ) ( ((a) < (b)) ? (a) : (b) )
#endif

//#define DEBUGMATRIX

typedef unsigned short mtype;

/* Read sequence from a file to a char vector.
 Filename is passed as parameter */

char* read_seq(char *fname) {
	//file pointer
	FILE *fseq = NULL;
	//sequence size
	long size = 0;
	//sequence pointer
	char *seq = NULL;
	//sequence index
	int i = 0;

	//open file
	fseq = fopen(fname, "rt");
	if (fseq == NULL ) {
		printf("Error reading file %s\n", fname);
		exit(1);
	}

	//find out sequence size to allocate memory afterwards
	fseek(fseq, 0L, SEEK_END);
	size = ftell(fseq);
	rewind(fseq);

	//allocate memory (sequence)
	seq = (char *) calloc(size + 1, sizeof(char));
	if (seq == NULL ) {
		printf("Erro allocating memory for sequence %s.\n", fname);
		exit(1);
	}

	//read sequence from file
	while (!feof(fseq)) {
		seq[i] = fgetc(fseq);
		if ((seq[i] != '\n') && (seq[i] != EOF))
			i++;
	}
	//insert string terminator
	seq[i] = '\0';

	//close file
	fclose(fseq);

	//return sequence pointer
	return seq;
}

mtype ** allocateScoreMatrix(int sizeA, int sizeB) {
	int i;
	//Allocate memory for LCS score matrix
	mtype ** scoreMatrix = (mtype **) malloc((sizeB + 1) * sizeof(mtype *));
	for (i = 0; i < (sizeB + 1); i++)
		scoreMatrix[i] = (mtype *) malloc((sizeA + 1) * sizeof(mtype));
	return scoreMatrix;
}

void initScoreMatrix(mtype ** scoreMatrix, int sizeA, int sizeB) {
	int i, j;
	//Fill first line of LCS score matrix with zeroes
	for (j = 0; j < (sizeA + 1); j++)
		scoreMatrix[0][j] = 0;

	//Do the same for the first collumn
	for (i = 1; i < (sizeB + 1); i++)
		scoreMatrix[i][0] = 0;
}

int LCS(mtype ** scoreMatrix, int sizeA, int sizeB, char * seqA, char *seqB) {
	int i, j, s;
	int block_rows, block_cols;
	int rank, size, nthreads;
	MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size); // total mpi processes
	nthreads = omp_get_max_threads();

	block_rows = min(size * nthreads * nthreads, sizeA);
	block_rows = min(block_rows, sizeB);
	block_cols = block_rows;

	block_rows = 2;
	block_cols = 2;

	int num_block_rows = (sizeB + block_rows - 1) / block_rows;
	int num_block_cols = (sizeA + block_cols - 1) / block_cols;

	int j_aux = -1;
	int ib_aux = 0;
	int jb_aux = 0;

	// iterate through the blocks diagonals using wavefront
	for (int d_block = 0; d_block < num_block_rows + num_block_cols; d_block++) {
		for (int i_block = 0; i_block < num_block_rows; i_block++) {
			int j_block = d_block - i_block - 1;
			if (j_block < 0 || j_block >= num_block_cols)
				continue;

			if (j_block > j_aux) {
				ib_aux = i_block + floor((j_block - i_block) / 2);
				jb_aux = j_block - floor((j_block - i_block) / 2);
			}
			j_aux = j_block;

			// ownership for half of blocks diagonal
			int half = 0;
			if (i_block > ib_aux && j_block < jb_aux)
				half = 1;
			if (rank != half)
				continue;

			// +1 because we do not use i=0 || j=0
			int row_start = (i_block * block_rows) + 1;
			int row_end = min(row_start + block_rows - 1, sizeB);

			int col_start = (j_block * block_cols) + 1;
			int col_end = min(col_start + block_cols - 1, sizeA);

			// iterate through the cells diagonals in the block using wavefront
			for (int d = row_start + col_start; d <= row_end + col_end; d++) {
				// OpenMP parallel over the diagonals
				#pragma omp parallel for private(i, j) schedule(runtime)
				for (i = row_start; i <= row_end; i++) {
					j = d - i;
					if (j >= col_start && j <= col_end) {
						int i_send, j_send, i_rec, j_rec;

						// receive data from other ranks
						if (i > 1 && j > 1) {
							if (!half) {
								if (i > 1) {	//has a top neighbor
									i_send = i-1;
									j_send = j;
									MPI_Send(&i_send, 0, MPI_INT, 1, 1, MPI_COMM_WORLD);
									MPI_Send(&j_send, 0, MPI_INT, 1, 2, MPI_COMM_WORLD);
									MPI_Send(&scoreMatrix[i-1][j], 0, MPI_INT, 1, 0, MPI_COMM_WORLD);
									printf("%d: Message sent	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i, j-1, scoreMatrix[i][j-1]);
								}
								if (j > 1) {	// has a left neighbor
									i_send = i-1;
									j_send = j;
									MPI_Send(&i_send, 0, MPI_INT, 1, 1, MPI_COMM_WORLD);
									MPI_Send(&j_send, 0, MPI_INT, 1, 2, MPI_COMM_WORLD);
									MPI_Send(&scoreMatrix[i][j-1], 0, MPI_INT, 1, 0, MPI_COMM_WORLD);
									printf("%d: Message sent	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i, j-1, scoreMatrix[i][j-1]);
								}
								if (i > 1 && j > 1) {	// has a top left neighbor
									i_send = i-1;
									j_send = j;
									MPI_Send(&i_send, 0, MPI_INT, 1, 1, MPI_COMM_WORLD);
									MPI_Send(&j_send, 0, MPI_INT, 1, 2, MPI_COMM_WORLD);
									MPI_Send(&scoreMatrix[i-1][j-1], 0, MPI_INT, 1, 0, MPI_COMM_WORLD);
									printf("%d: Message sent	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i, j-1, scoreMatrix[i][j-1]);
								}
							} else {
								if (i > 1) {	//has a top neighbor
									MPI_Recv(&i_rec, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
									MPI_Recv(&j_rec, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
									MPI_Recv(&scoreMatrix[i_rec][j_rec], 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
									printf("%d: Message received	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i, j-1, scoreMatrix[i][j-1]);
								}
								if (j > 1) {	// has a left neighbor
									MPI_Recv(&i_rec, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
									MPI_Recv(&j_rec, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
									MPI_Recv(&scoreMatrix[i_rec][j_rec], 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
									printf("%d: Message received	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i, j-1, scoreMatrix[i][j-1]);
								}
								if (i > 1 && j > 1) {	// has a top left neighbor
									MPI_Recv(&i_rec, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
									MPI_Recv(&j_rec, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
									MPI_Recv(&scoreMatrix[i_rec][j_rec], 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
									printf("%d: Message received	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i, j-1, scoreMatrix[i][j-1]);
								}
							}
						}

						// actual computation
						if (seqA[j-1] == seqB[i-1]) {
							scoreMatrix[i][j] = scoreMatrix[i-1][j-1] + 1;
						} else {
							scoreMatrix[i][j] = max(scoreMatrix[i-1][j], scoreMatrix[i][j-1]);
						}

						// send data to rank 0 
						if (half) {
							i_send = i-1;
							j_send = j;
							MPI_Send(&i_send, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
							MPI_Send(&j_send, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
							MPI_Send(&scoreMatrix[i][j], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
							printf("%d: Message sent after computing	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i, j, scoreMatrix[i][j]);
						} else {
							MPI_Recv(&i_rec, 0, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
							MPI_Recv(&j_rec, 0, MPI_INT, 1, 2, MPI_COMM_WORLD, &status);
							MPI_Recv(&scoreMatrix[i_rec][j_rec], 0, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
							printf("%d: Message received after computing	[%d] %d,%d = %d\n", rank, status.MPI_TAG, i_rec, j_rec, scoreMatrix[i_rec][j_rec]);
						}
						printf("%d: %d,%d = %d\n", rank, i, j, scoreMatrix[i][j]);
					}
				}
			}

		}
		// sincronization between wavefronts
		MPI_Barrier(MPI_COMM_WORLD);
	}
	printf("%d: %d,%d = %d\n", rank, sizeB, sizeA, scoreMatrix[sizeB][sizeA]);
	return scoreMatrix[sizeB][sizeA];
}

void printMatrix(char * seqA, char * seqB, mtype ** scoreMatrix, int sizeA,
		int sizeB) {
	int i, j;

	//print header
	printf("Score Matrix:\n");
	printf("========================================\n");

	//print LCS score matrix allong with sequences

	printf("    ");
	printf("%5c   ", ' ');

	for (j = 0; j < sizeA; j++)
		printf("%5c   ", seqA[j]);
	printf("\n");
	for (i = 0; i < sizeB + 1; i++) {
		if (i == 0)
			printf("    ");
		else
			printf("%c   ", seqB[i - 1]);
		for (j = 0; j < sizeA + 1; j++) {
			printf("%5d   ", scoreMatrix[i][j]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

void freeScoreMatrix(mtype **scoreMatrix, int sizeB) {
	int i;
	for (i = 0; i < (sizeB + 1); i++)
		free(scoreMatrix[i]);
	free(scoreMatrix);
}

int main(int argc, char ** argv) {
	// arg 1	nth
	// arg 2	omp_sched_kind
	// arg 3	chunk size
	// arg 4	fileA
	// arg 5	file B
	if (argc != 6) {
		fprintf(stderr, "Usage: %s <num_threads> <schedule_type> <chunk_size> <fileA> <fileB>\n", argv[0]);
		return 1;
	}
	
	// sequence pointers for both sequences
	char *seqA, *seqB;

	// sizes of both sequences
	int sizeA, sizeB;

	//read both sequences
	seqA = read_seq(argv[4]);
	seqB = read_seq(argv[5]);

	//find out sizes
	sizeA = strlen(seqA);
	sizeB = strlen(seqB);

	// allocate LCS score matrix
	mtype ** scoreMatrix = allocateScoreMatrix(sizeA, sizeB);

	//initialize LCS score matrix
	initScoreMatrix(scoreMatrix, sizeA, sizeB);

	//fill up the rest of the matrix and return final score (element locate at the last line and collumn)
	
	int num_threads = atoi(argv[1]);
	int sched_t = atoi(argv[2]);
	int	chunk_size = atoi(argv[3]);

	omp_sched_t sched;

	switch (sched_t) {
		case 1:
			sched = omp_sched_static;
			break;
		case 2:
			sched = omp_sched_dynamic;
			break;
		case 3:
			sched = omp_sched_guided;
			break;
		case 4:
			sched = omp_sched_auto;
			break;
		default:
			fprintf(stderr, "Invalid schedule type");
			exit(EXIT_FAILURE);
	}

	omp_set_num_threads(num_threads);
	omp_set_schedule(sched, chunk_size);

	MPI_Init(&argc, &argv);
	int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	mtype score = LCS(scoreMatrix, sizeA, sizeB, seqA, seqB);

	/* if you wish to see the entire score matrix,
	 for debug purposes, define DEBUGMATRIX. */
#ifdef DEBUGMATRIX
	printMatrix(seqA, seqB, scoreMatrix, sizeA, sizeB);
#endif

	//print score
	// my rank 1 calculates the last block, so it has the correct result
	//if (rank)
		printf("\nScore: %d\n", score);
	MPI_Finalize();

	//free score matrix
	freeScoreMatrix(scoreMatrix, sizeB);

	return EXIT_SUCCESS;
}
