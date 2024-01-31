#include <stdio.h>
#include <stdlib.h>
#include "libconjunto.h"
#define TAM 100

int main(){
	int vetor[TAM], M[TAM], U[TAM], I[TAM];
	preencher(vetor);
	if (ehvazio(vetor) == 1)
		printf("Não é vazio.\n");
	else
		printf("É vazio.\n");
	int cont = contador(vetor);
	printf("O vetor inserido tem tamnho %d", cont);
	preencheAleatorio(M);
	printf("União com vetor aleatório:\n");
	imprimirVetor(U);
	printf("Intersecção com vetor aleatório:\n");
	imprimirVetor(I);
	return 0;
}
