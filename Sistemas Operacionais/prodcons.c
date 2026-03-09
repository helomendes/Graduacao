#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUMCONS 1
#define NUMPROD 2
#define BUFFERSIZE 1000

#define RED "\x1B[31m"
#define CYN "\x1B[36m"
#define RESET "\x1B[0m"

pthread_t cons[NUMCONS];
pthread_t prod[NUMPROD];
pthread_mutex_t buffer_mutex;
int buffer[BUFFERSIZE];
int currentidx;
sem_t buffer_full, buffer_empty;

void *produtor(void *arg) {
	int n;
	while (1) {
		n = rand()%1000;
		printf(RED "Esperando o buffer_full\n" RESET);
		sem_wait(&buffer_full);
		pthread_mutex_lock(&buffer_mutex);
			buffer[currentidx++] = n;
			printf(RED "Produzindo numero %d\n" RESET, n);
		pthread_mutex_unlock(&buffer_mutex);
		printf(RED "Liberando o buffer_empty\n" RESET);
		sem_post(&buffer_empty);
		sleep(1 + rand()%5);
	}
}

void *consumidor(void *arg) {
	int n;
	while (1) {
		printf(CYN "Esperando o buffer_empty\n" RESET);
		sem_wait(&buffer_empty);
		pthread_mutex_lock(&buffer_mutex); 
			n = buffer[--currentidx];
			printf(CYN "Consumindo numero %d\n" RESET, n);
		pthread_mutex_unlock(&buffer_mutex);
		printf(CYN "Liberando o buffer_full\n" RESET);
		sem_post(&buffer_full);
		sleep(1 + rand()%5);
	}
}

int main() {
	int i;
	printf("%d\n", currentidx);
	pthread_mutex_init(&buffer_mutex, NULL);
	sem_init(&buffer_full, 0, BUFFERSIZE); // esse é inicializado com valor, por isso o produtor nao fica esperando
	sem_init(&buffer_empty, 0, 0);

	for (i = 0; i < NUMCONS; i++)
		pthread_create(&(cons[i]), NULL, consumidor, NULL);
	for (i = 0; i < NUMPROD; i++)
		pthread_create(&(prod[i]), NULL, produtor, NULL);
	for (i = 0; i < NUMCONS; i++)
		pthread_join(cons[i], NULL);
	for (i = 0; i < NUMPROD; i++)
		pthread_join(prod[i], NULL);
	return 0;
}
