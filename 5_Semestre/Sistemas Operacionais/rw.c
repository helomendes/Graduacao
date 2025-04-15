#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

typedef struct {
	int buffer;
	int numreaders;
	int writerswaiting;
	pthread_mutex_t mutex;
	sem_t wlock;

	pthread_cond_t readerwait;
	pthread_cond_t writerwait;
} buffer;

void *readerfunction(void *voidbuffer) {
	buffer* b = voidbuffer;
	while (1) {
		pthread_mutex_lock(&b->mutex);
			while (b->writerswaiting > 0)
				pthread_cond_wait(&b->readerwait, &b->mutex);
			if (b->numreaders == 0) {
				pthread_mutex_unlock(&b->mutex);
				sem_wait(&b->wlock); // o semafaro é inicializado com 1 então não espera nada na primeira vez
									 // mas aqui ele está esperando os writers sinalizarem que pode
				pthread_mutex_lock(&b->mutex);
			}
			b->numreaders++;
		pthread_mutex_unlock(&b->mutex);

		usleep(10000 * (rand()%4 + 1));
		printf("%d\n", b->buffer);

		pthread_mutex_lock(&b->mutex);
			b->numreaders--;
			if (b->numreaders == 0) {
				sem_post(&b->wlock); // sinaliza aos writers que podem escrever
				pthread_cond_signal(&b->writerwait);
			}
		pthread_mutex_unlock(&b->mutex);
	}
	pthread_exit(NULL);
}

void *writerfunction(void *voidbuffer) {
	buffer *b = voidbuffer;
	int r;
	while (1) {
		pthread_mutex_lock(&b->mutex);
			b->writerswaiting++;
			while (sem_trywait(&b->wlock) != 0)
				pthread_cond_wait(&b->writerwait, &b->mutex);
			b->writerswaiting--;

			r = rand();
			printf("Inserting %d\n", r);
			b->buffer = r;

			if (b->writerswaiting > 0)
				pthread_cond_signal(&b->writerwait);
			else
				pthread_cond_broadcast(&b->readerwait);
			
			sem_post(&b->wlock);
			pthread_mutex_unlock(&b->mutex);
			usleep(1000000 * (rand()%4 + 1));
	}
	pthread_exit(NULL);
}

int main() {
	srand(time(NULL));
	buffer* b = malloc(sizeof(buffer));
	b->numreaders = 0;
	b->writerswaiting = 0;
	pthread_mutex_init(&b->mutex, NULL);
	sem_init(&b->wlock, 0, 1);
	pthread_cond_init(&b->readerwait, NULL);
	pthread_cond_init(&b->writerwait, NULL);

	pthread_t rthreads[4];
	pthread_t wthreads[4];

	for (int i = 0; i < 4; i++) {
		pthread_create(&rthreads[i], NULL, readerfunction, b);
		pthread_create(&wthreads[i], NULL, writerfunction, b);
	}
	for (int i = 0; i < 4; i++) {
		pthread_join(rthreads[i], NULL);
		pthread_join(wthreads[i], NULL);
	}
	pthread_exit(NULL);
	return 0;
}
