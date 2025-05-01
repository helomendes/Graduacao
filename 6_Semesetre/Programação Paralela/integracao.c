#include <stdio.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 16

static long num_steps = 100000;
double step;

void sequential() {
	clock_t start, end;
	double pi, x, sequential;
	double sum = 0.0;

	start = clock();

	for (int i = 0; i < num_steps; i ++) {
		x = (i + 0.5) * step;
		sum += 4.0 / (1.0 + x*x);
	}

	end = clock();

	pi = sum*step;
	
	sequential = ((double)(end - start))/CLOCKS_PER_SEC;
	printf("Tempo Sequencial: %f\n", sequential);
	printf("pi = %f\n", pi);
}

void parallel() {
	clock_t start, end;
	int nthreads;
	double pi, parallel;
	double sums[NUM_THREADS][8];

	#pragma omp parallel num_threads(NUM_THREADS)
	{
		int i, ID, nthrds;
		double x;
		ID = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (ID == 0)
			nthreads = nthrds;

		start = clock();

		for (i = ID, sums[ID][0] = 0.0; i < num_steps; i += nthrds) {
			x = (i + 0.5) * step;
			sums[ID][0] += 4.0 / (1.0 + x*x);
		}

		end = clock();

	}
	for (int i = 0, pi = 0.0; i < NUM_THREADS; i++)
		pi += sums[i][0]*step;

	parallel = ((double)(end - start))/CLOCKS_PER_SEC;
	printf("Tempo Paralelo: %f\n", parallel);
	printf("pi = %f\n", pi);
}

int main() {
	step = 1.0 /(double)num_steps;
	
	sequential();
	printf("\n");
	parallel();

	return 0;
}
