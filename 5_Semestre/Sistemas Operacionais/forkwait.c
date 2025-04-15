#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int r, pid, s;
	r = fork();

	if (r < 0) {
		fprintf(stderr, "Fork failed\n");
		exit(-1);
	} else if (r == 0) {
		printf("sou o filho com PID: %d, meu pai tem PID: %d\n", getpid(), getppid());
	} else {
		printf("sou o processo pai com PID: %d, criei um filho com PID: %d\n", getpid(), r);
		pid = wait(&s);
		printf("meu filho com PID: %d terminou coms status %d\n", pid, s);
		exit(0);
	}
	return 0;
}
