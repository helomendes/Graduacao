#include <stdio.h>
#include <omp.h>

// BARREIRA
// Barrier: cada thread espera até que as demais cheguem
#pragma omp parallel
{
	int id = omp_get_thread_num();
	A[id] = big_calc1(id);
	#pragma omp barrier
	B[id] = big_calc2(id, A);
}

// CRITICAL
// Exclusão mútua: apenas uma thread pode entrar por vez
float res;
#pragma omp parallel
{
	float B;
	int i, id, nthrds;
	id = omp_get_thread_num();
	nthrds = omp_get_num_threads();
	for (i = id; i < niters; i += nthreads) {
		B = big_job(i);
	#pragma omp critical	// #pragma omp critical(trechoB)
							// podemos nomear um trecho critical
							// não conflitar com outras contruções
		res += consume(B);	// as threads esperam sua vez
							// apenas uma chama consume() por vez
	}
}

// ATOMIC
// Atomic provê exclusão mútua para apenas atualizações na memória
#pragma omp parallel
{
	double tmp, B;
	B = DOIT();
	tmp = big_ugly(B);
	#pragma omp atomic
	X += tmp;
}
