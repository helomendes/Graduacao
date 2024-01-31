#include <stdio.h>
#include <stdlib.h>
#include "libconjunto.h"
#define N 100

int main(){
	int vetor[N];
	preencher(vetor);
	if (ehvazio(vetor) == 0)
		printf("É vazio\n");
	else
		printf("Não é vazio\n");
	int tam = contador(vetor);
	imprimirVetor(vetor, tam);
	int M[N];
	preencherAleatorio(M);
	printf("\nVetor aleatório:\n");
	imprimirVetor(M, N);
	int n = N + tam;
	int U[n];
	uniao(vetor, M, U, tam);
	int I[N];
	limparVetor(I, N);
	interseccao(vetor, M, I, tam);
	return 0;
}
