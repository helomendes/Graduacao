#include <stdio.h>
#include <omp.h>

void exemplo_loop() {
	# pragma omp parallel
	{
		# pragma omp for	// a variavel i será feita privada para cada thread por padrão
							// voce poderia fazer isso explicitamente com a clausula
							// private(i)
		for (i = 0; i < n; i++) {
			neat_stuff(i);
		}
	}
}

void sequential() {
	for (int i = 0; i < n; i++) {
		a[i] = a[i] + b[i];
	}
}

void parallel() {
	# pragma omp parallel
	{
		int id, i, chunk, nthrds, istart, iend;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		chunk = (N + nthreads - 1) / nthrds;
		istart = id * chunk;
		iend = min(start + chunk, n);
		for (i = istart; i < iend; i++) {
			a[i] = a[i] + b[i];
		}
	}
}

void parallel_worksharing() {
	# pragma omp parallel
	# pragma omp for
	for (int i = 0; i < n; i++) {
		a[i] = a[i] + b[i];
	}
}

void shortcut() {
	double res[MAX];
	int i;
	# pragma omp parallel
	{
		# pragma omp for
		for (int i = 0; i < MAX; i++)
			res[i] = huge();
	}

	// ==
	
	# pragma omp parallel for
		for (int i = 0; i < MAX; i++)
			res[i] = huge();
}
