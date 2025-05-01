#include <stdio.h>
#include <omp.h>

int main() {
	printf("Sequential\n");
	int ID = omp_get_thread_num();
	printf("Hello (%d) ", ID);
	printf("world (%d)\n", ID);

	printf("\nParallel\n");
	//#pragma omp parallel
	#pragma omp parallel num_threads(16)
	{
		ID = omp_get_thread_num();
		printf("Hello (%d) ", ID);
		printf("world (%d)\n", ID);
	}
	return 0;
}
