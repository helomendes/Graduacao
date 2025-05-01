#include <stdio.h>
#include <omp.h>

int main() {
	int ID = 0;

	// Sequential
	printf("### Sequential ###\n");
	printf("Hello (%d) ", ID);
	printf("world (%d)\n", ID);
	printf("\n");

	// Parallel
	printf("### Parallel 0 ###\n");
	#pragma omp parallel
	{
		printf(" hello(%d) ", ID);
		printf(" world(%d) ", ID);
	}
	printf("\n\n");
	
	printf("### Parallel 1 ###\n");
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		printf(" hello(%d) ", ID);
		printf(" world(%d) ", ID);
	}
	printf("\n\n");
	return 0;
}
