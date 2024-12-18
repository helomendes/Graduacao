#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t r;
	r = fork();
	if (r < 0) {
		fprintf(stderr, "Fork failed");
		exit(-1);
	} else if (r == 0) {
		execlp("/bn/ls", "ls", NULL);
	} else {
		wait(NULL);
		printf("Child complete\n");
		exit(0);
	}
	return 0;
}
