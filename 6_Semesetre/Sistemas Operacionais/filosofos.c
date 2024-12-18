#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
	pthread_mutex_t *fork_lft, *fork_rgt;
	const char *name;
	pthread_t thread;
} philosopher;

void *philosopherfunction(void *p) {
	philosopher *p_ptr = (philosopher*)p;
	while (1) {
		printf("%s is thinking\n", p_ptr->name);
		sleep(1 + rand()%5);

		printf("%s is hungry\n", p_ptr->name);

		pthread_mutex_lock(p_ptr->fork_lft);
		pthread_mutex_lock(p_ptr->fork_rgt);

		printf("%s is eating\n", p_ptr->name);
		sleep(1 + rand()%8);

		pthread_mutex_unlock(p_ptr->fork_lft);
		pthread_mutex_unlock(p_ptr->fork_rgt);
		printf("%s finished eating\n", p_ptr->name);
	}
	return NULL;
}

int main() {
	const char *nameList[] = {"Kant", "Guatma", "Russel", "Aristotle", "Bart"};
	pthread_mutex_t forks[5];
	philosopher** philosophers = malloc(sizeof(*philosophers) * 5);
	int i;

	for (i = 0; i < 5; i++)
		pthread_mutex_init(&forks[i], NULL);
	for (i = 0; i < 4; i++) {
		philosophers[i] = malloc(sizeof(*philosophers[i]));
		philosophers[i]->name = nameList[i];
		philosophers[i]->fork_lft = &forks[i];
		philosophers[i]->fork_rgt = &forks[(i+1)%5];
		pthread_create( &philosophers[i]->thread, NULL, philosopherfunction, philosophers[i]);
	}
	philosophers[i] = malloc(sizeof(*philosophers[i]));
	philosophers[i]->name = nameList[i];
	philosophers[i]->fork_lft = &forks[i];
	philosophers[i]->fork_rgt = &forks[(i+1)%5];
	pthread_create(&philosophers[i]->thread, NULL, philosopherfunction, philosophers[i]);

	pthread_exit(NULL);
	return 0;
}
