#include <stdio.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 2
#define PAD 8

static long num_steps = 100000;
double step;

int main() {
	int i, nthreads;
	double pi;
	step = 1.0 /(double)num_steps;
	
	double sums[NUM_THREADS][PAD];
	
	clock_t start_seq, end_seq, start_par, end_par;

	#pragma omp parallel num_threads(NUM_THREADS)
	{
		int i, ID, nthrds;
		double x;
		
		ID = omp_get_thread_num();
		nthrds = omp_get_num_threads();

		if (ID == 0)
			nthreads = nthrds;
		start_par = clock();
		for (i = ID, sums[ID][0] = 0.0; i < num_steps; i += nthrds) {
			x = (i + 0.5) * step;
			sums[ID][0] += 4.0 / (1.0 + x*x);
		}
		end_par = clock();
	}

	for (i = 0, pi = 0.0; i < NUM_THREADS; i++)
		pi += sums[i][0]*step;
	
	double parallel = ((double)(end_par - start_par))/CLOCKS_PER_SEC;

	printf("Tempo Paralelo: %f\n", parallel);
	printf("pi = %f\n", pi);
	
	return 0;
}
