#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;

#define NUM_THREADS 2

double sequential_pi() {
	int i;
	double x, pi, sum = 0.0;
	step = 1.0 / (double)num_steps;
	for (i = 0; i < num_steps; i++) {
		x = (i + 0.5) * step; // rectangle width
		sum = sum + 4.0 / (1.0 + x*x); // sum += rectangle area
	}
	pi = step * sum;

	return pi;
}

double parallel_pi() {
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

	return pi;
}

double parallel_slides() {
	int i, nthreads;
	double pi, sum[NUM_THREADS];	// promovemos um escalar para um vetor
									// dimensionado pelo número de threads
								 	// para prevenir condições de corrida
	step = 1.0/(double)num_steps;

	#pragma omp parallel num_threads(NUM_THREADS)
	{
		int i, id, nthrds;
		double x;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id == 0)
			nthreads = nthrds;	// apenas uma thread pode copiar o número de thread para
								// a variável global para certificar que múltiplas threads gravando
								// no mesmo endereço não gerem conflito
								// sempre verifique o número de threads
		for (i = id, sum[id] = 0.0; i < num_steps; i += nthrds) {	// este é um truque
																	// comum em programas SPMD para criar uma distribuição
																	// cíclica das iterações do loop
			x = (i + 0.5)*step;
			sum[id] += 4.0/(1.0 + x*x);	// usamos uma variável global para evitar
										// perder dados
		}
	}
	for (i = 0, pi = 0.0; i < nthreads; i++)
		pi += sum[i] * step;

	return pi;
}

int main() {
	double pi;
	pi = sequential_pi();
	printf("Sequential pi = %f\n", pi);

	pi = parallel_pi();
	printf("Parallel pi = %f\n", pi);

	pi = parallel_pi();
	printf("Parallel pi corrected = %f\n", pi);
	return 0;
}
