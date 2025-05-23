#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNT_MAX 10
int count = 0;
pthread_mutex_t mutexsum;

void *countSum(void *tid) {
	long id = (long)tid;

	while(1) {
		pthread_mutex_lock(&mutexsum);
			if (count >= COUNT_MAX) {
				pthread_mutex_unlock(&mutexsum);
				break;
			}
			count++;
			printf("Thread %ld: contador em %d\n", id, count);
		pthread_mutex_unlock(&mutexsum);
		sleep(rand() % 3);
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t t1, t2;
	int create;
	long num;

	pthread_mutex_init(&mutexsum, NULL);
	num = 1;
	printf("Main: criando a thread %ld\n", num);
	create = pthread_create(&t1, NULL, countSum, (void *)num);


	num = 2;
	printf("Main: criando a thread %ld\n", num);
	create = pthread_create(&t2, NULL, countSum, (void *)num);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Main: finalizando\n");
	
	pthread_mutex_destroy(&mutexsum);

	return 0;
}
