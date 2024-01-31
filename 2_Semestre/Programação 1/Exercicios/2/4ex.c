#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void preencherAleatorio(int v[TAM], int maxVal){
	int i;
	for(i = 0; i < TAM; i++)
		v[i] = rand()%maxVal;
}

int main(){
	int v[TAM];
	int *pv;
	pv = v;
	preencherAleatorio(v, 1024);
	for (int i = 0; i < TAM; i++){
		printf("%d\t", *pv);
		pv++;
	}
	printf("\n");
	return 0;
}
