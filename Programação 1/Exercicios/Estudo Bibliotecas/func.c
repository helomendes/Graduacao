#include "libconjunto.h"
#include <stdio.h>
#include <stdlib.h>

int ehvazio(int vetor[100]){
	for(int i = 0; i < 100; i++){
		if(vetor[i] >= 0)
			return 1;
		return 0;
	}
}

int contador(int vetor[100]){
	int cont = 0;
	for(int i = 0; i < 100; i++){
		if (vetor[i] >= 0)
			cont = cont + 1;
	}
	return cont;
}

void preencher(int vetor[100]){
	int i = 0;
	printf("Insira o vetor, digite um número negativo para encerrar.\n");
	for(i; i < 100 && i >= 0; i++)
		scanf("%d", &vetor[i]);
	vetor[i+1] = -1;
}

void preencheAleatorio(int M[100]){
	for(int i = 0; i < 100; i++)
		M[i] = rand();
}

void uniao(int vetor[100], int M[100], int U[100], int cont){
	for(int u = 0; u < 100+cont; u++){
		for(int i = 0; i < 100; i++)
			U[u] = M[i];
		for(int i = 0; i < cont; i++)
			U[u] = vetor[i];
	}
}

void interseccao(int vetor[100], int M[100], int I[100]){
	for(int u = 0; u < 100; u++){
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				if (vetor[i] = M[j])
					I[u] = vetor[i];
			}
		}
	}
}

void imprimirVetor(int vetor[100]){
	for(int i = 0; i < 100; i++)
		printf("%d\t", vetor[i]);
}

