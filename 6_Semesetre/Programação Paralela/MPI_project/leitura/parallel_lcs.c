#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <math.h>
#include <omp.h>
#include <time.h>

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
	MPI_Request req;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size); // total mpi processes
	nthreads = omp_get_max_threads();

	int calc = min(nthreads, sizeA);
	calc = min(calc, sizeB);

	block_rows = sizeB / calc;
	block_cols = sizeA / calc;

	int num_block_rows  = calc + (sizeB % calc);
	int num_block_cols = (size*nthreads*nthreads);

	int j_aux = -1;
	int ib_aux = 0;
	int jb_aux = 0;

	mtype ** blockMatrix = allocateScoreMatrix(num_block_rows, num_block_cols);
	initScoreMatrix(blockMatrix, num_block_rows, num_block_cols);

	// iterate through the blocks diagonals using wavefront
	for (int d_block = 0; d_block < num_block_rows + num_block_cols; d_block++) {
		for (int i_block = 0; i_block < num_block_rows; i_block++) {
			clock_t test_start = clock();
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
			blockMatrix[i_block][j_block] = half;


			// +1 because we do not use i=0 || j=0
			int row_start = (i_block * block_rows) + 1;
			int row_end = min(row_start + block_rows - 1, sizeB);

			int col_start = (j_block * block_cols) + 1;
			int col_end = min(col_start + block_cols - 1, sizeA);

			if (rank == half) {
				// iterate through the cells diagonals in the block using wavefront
				clock_t diagonal_start = clock();
				for (int d = row_start + col_start; d <= row_end + col_end; d++) {
					// OpenMP parallel over the diagonals
					#pragma omp parallel for private(i, j) schedule(runtime)
					for (i = row_start; i <= row_end; i++) {
						j = d - i;
						if (j < col_start || j > col_end)
							continue;

						// actual computation
						if (seqA[j-1] == seqB[i-1]) {
							scoreMatrix[i][j] = scoreMatrix[i-1][j-1] + 1;
						} else {
							scoreMatrix[i][j] = max(scoreMatrix[i-1][j], scoreMatrix[i][j-1]);
						}
						//printf("[Rank %d]: i=%d, j=%d, val=%d\n", rank, i, j, scoreMatrix[i][j]);
					}
				}
				clock_t diagonal_end = clock();
				double diagonal_computation = ((double)(diagonal_end - diagonal_start))/CLOCKS_PER_SEC;
				//printf("\t[Rank %d]: Computed block [%d][%d] = %f\n", rank, i_block, j_block, diagonal_computation);
			}
			MPI_Barrier(MPI_COMM_WORLD);

			// send to rank 0
			clock_t com_start = clock();
			if (blockMatrix[i_block][j_block] == 1) {
				//printf("[Rank %d]: Communicating computations\n", rank);
				for (int ix = row_start; ix <= row_end; ix++) {
					for (int jx = col_start; jx <= col_end; jx++) {
						MPI_Barrier(MPI_COMM_WORLD);
						if (rank) {
							MPI_Send(&scoreMatrix[ix][jx], 1, MPI_INT, 0, 100*ix+jx, MPI_COMM_WORLD);
							//printf("[Rank %d]: Message %d sent i=%d, j=%d, val=%d\n", rank, 100*ix+jx, ix, jx, scoreMatrix[ix][jx]);
						} else {
							MPI_Recv(&scoreMatrix[ix][jx], 1, MPI_INT, 1, 100*ix+jx, MPI_COMM_WORLD, &status);
							//printf("[Rank %d]: Message %d recv i=%d, j=%d, val=%d\n", rank, 100*ix+jx, ix, jx, scoreMatrix[ix][jx]);
						}
					}
				}
			// send the dependencies
			} else if (blockMatrix[i_block][j_block] == 0) {
				//printf("[Rank %d]: Communicating the dependencies\n", rank);
				int ix, jx;
				// send the last row
				ix = row_end;
				for (jx = col_start; jx <= col_end; jx++) {
					MPI_Barrier(MPI_COMM_WORLD);
					if (rank == 0) {
						MPI_Send(&scoreMatrix[ix][jx], 1, MPI_INT, 1, 10000*ix+10*jx, MPI_COMM_WORLD);
						//printf("[Rank %d]: Message %d sent i=%d, j=%d, val=%d\n", rank, 10000*ix+10*jx, ix, jx, scoreMatrix[ix][jx]);
					} else {
						MPI_Recv(&scoreMatrix[ix][jx], 1, MPI_INT, 0, 10000*ix+10*jx, MPI_COMM_WORLD, &status);
						//printf("[Rank %d]: Message %d recv i=%d, j=%d, val=%d\n", rank, 10000*ix+10*jx, ix, jx, scoreMatrix[ix][jx]);
					}
				}
				// send the last colune
				jx = col_end;
				for (ix = row_start; ix <= row_end; ix++) {
					MPI_Barrier(MPI_COMM_WORLD);
					if (rank == 0) {
						MPI_Send(&scoreMatrix[ix][jx], 1, MPI_INT, 1, 10000*ix+100*jx, MPI_COMM_WORLD);
						//printf("[Rank %d]: Message %d sent i=%d, j=%d, val=%d\n", rank, 10000*ix+100*jx, ix, jx, scoreMatrix[ix][jx]);
					} else {
						MPI_Recv(&scoreMatrix[ix][jx], 1, MPI_INT, 0, 10000*ix+100*jx, MPI_COMM_WORLD, &status);
						//printf("[Rank %d]: Message %d recv i=%d, j=%d, val=%d\n", rank, 10000*ix+100*jx, ix, jx, scoreMatrix[ix][jx]);
					}
				}
			}
			clock_t com_end = clock();
			double com_total = ((double)(com_end - com_start))/CLOCKS_PER_SEC;
			//printf("\t[Rank %d]: Communication time: %f\n", rank, com_total);
		}
		// sincronization between wavefronts
		MPI_Barrier(MPI_COMM_WORLD);
	}
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
	clock_t start_main, end_main, start_lcs, end_lcs;
	start_main = clock();
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
		case 0:
			sched = omp_sched_static;
			break;
		case 1:
			sched = omp_sched_dynamic;
			break;
		case 2:
			sched = omp_sched_guided;
			break;
		case 3:
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
	start_lcs = clock();
	mtype score = LCS(scoreMatrix, sizeA, sizeB, seqA, seqB);
	end_lcs = clock();

	/* if you wish to see the entire score matrix,
	 for debug purposes, define DEBUGMATRIX. */
#ifdef DEBUGMATRIX
	printMatrix(seqA, seqB, scoreMatrix, sizeA, sizeB);
#endif

	//print score
	if (rank == 0)
		printf("Score: %d\n", score);
	end_main = clock();
	double total_main = ((double)(end_main - start_main))/CLOCKS_PER_SEC;
	double total_lcs = ((double)(end_lcs - start_lcs))/CLOCKS_PER_SEC;
	printf("Total time: %f\n", total_main);
	printf("LCS time: %f\n", total_lcs);

	//free score matrix
	freeScoreMatrix(scoreMatrix, sizeB);
	MPI_Finalize();
	if (rank != 0)
		exit(0);
	return EXIT_SUCCESS;
}
