#include <stdio.h>
#include <time.h>

int main(){
	printf("Pulsos de clock até o momento: %ld\nEm segundos: %ld\n", clock(), (clock()/CLOCKS_PER_SEC));
	printf("printf aleatório\n");
	printf("Mais um teste da quantidade de pulsos de clock: %ld\nEm segundos: %ld\n", clock(), (clock()/CLOCKS_PER_SEC));
	return 0;
}
