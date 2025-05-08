#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

double work(double *a, double *b, int n) {
	int i;
	double tmp, sum;
	sum = 0.0;

	#pragma omp simd private(tmp) reduction(+:sum)
	for (i = 0; i < n; i++) {
		tmp = a[i] + b[i];
		sum += tmp;
	}
	return sum;
}

int main() {
	int size = 1000000;
	double *a = malloc(sizeof(double) * size);
	double *b = malloc(sizeof(double) * size);

	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		a[i] = rand();
		b[i] = rand();
	}

	double ret = work(a, b, size);
	printf("%f\n", ret);
	
	return 0;
}
