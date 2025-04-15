#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3
#define COUNT_LIMIT 12
#define RED   "\x1B[31m"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

int count = 0;
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void *watch_count(void *t) {
	long my_id = (long)t;

	printf(RED "Iniciando watch_count: thread %ld\n" RESET, my_id);
	pthread_mutex_lock(&count_mutex);
		while(count < COUNT_LIMIT) {
			printf(RED "watch_count: thread %ld; Count = %d; esperando...\n" RESET, my_id, count);
			pthread_cond_wait(&count_threshold_cv, &count_mutex);
			// a função wait libera o mutex e espera pelo sinal da variavel de condição
			// isso suspende a thread até que o sinal seja enviado
			printf(RED "watch_count: thread %ld; Sinal da variável de condição recebido; Count = %d\n" RESET, my_id, count);
		}
		printf(RED "watch_count: thread %ld; Alterando o valor de count...\n" RESET, my_id);
		count += 125;
		printf(RED "watch_count: thread %ld; Count = %d\n" RESET, my_id, count);
		printf(RED "watch_count: thread %ld; Liberando mutex\n" RESET, my_id);
	pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}

void *inc_count(void *t) {
	int i;
	long my_id = (long)t;
	
	for (i = 0; i < 10; i++) {
		pthread_mutex_lock(&count_mutex);
			count++;
			if (count == COUNT_LIMIT) {
				printf(CYN "inc_count: thread %ld; Count = %d; Limite alcançado; " RESET, my_id, count);
				pthread_cond_signal(&count_threshold_cv);
				printf(CYN "enviando sinal\n" RESET);
			}
			printf(CYN "inc_count: thread %ld; Count = %d; Liberando mutex\n" RESET, my_id, count);
		pthread_mutex_unlock(&count_mutex);
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	int i, rc;
	long t1 = 1, t2 = 2, t3 = 3;
	pthread_t threads[3];

	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&count_threshold_cv, NULL);

	pthread_create(&threads[0], NULL, watch_count, (void *)t1);
	pthread_create(&threads[1], NULL, inc_count, (void *)t2);
	pthread_create(&threads[2], NULL, inc_count, (void *)t3);

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("Main: valor final de count = %d; Done.\n", count);
	
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	pthread_exit(NULL);
	return 0;
}
