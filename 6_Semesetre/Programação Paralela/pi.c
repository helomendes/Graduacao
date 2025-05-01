#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;

int main() {
	// SEQUENTIAL
	/*
	int i;
	double x, pi, sum = 0.0;
	step = 1.0 / (double)num_steps;
	for (i = 0; i < num_steps; i++) {
		x = (i + 0.5) * step; // rectangle width
		sum = sum + 4.0 / (1.0 + x*x); // sum += rectangle area
	}
	pi = step * sum;
	printf("pi = %f\n", pi);
	*/

	// PARALLEL
	int num_threads = 4;
	int i;
	double x[num_threads];
	double sums[num_threads];
	double pi;
	step = 1.0 / (double)num_steps;
	#pragma parallel num_threads(num_threads)
	{
		int id = omp_get_thread_num();
		for (i = 0; i < num_steps; i++) {
			x[id] = (i + 0.5) * step; // rectangle width
			sums[id] = sums[id] + 4.0 / (1.0 + x[id]*x[id]); // sum += rectangle area
		}
	}
	double sum = 0.0;
	for (i = 0; i < num_threads; i++)
		sum += sums[i];
	pi = step * sum;
	printf("pi = %f\n", pi);

	return 0;
}
