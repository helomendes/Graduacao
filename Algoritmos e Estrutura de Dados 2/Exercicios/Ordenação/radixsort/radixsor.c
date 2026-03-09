#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

//função para encontrar o maior elemento de um vetor
int maiorElemento(int v[], int n){
	int maior = (v[0]);
	for(int i = 1; i < n; i++)
		if(maior < (v[i]))
			maior = (v[i]);
	return maior;
}

void radixsort(int v[], int n){
	int maior = maiorElemento(v, n);
	for(int posicao = 1; maior/posicao > 0; posicao *= 10){
		countingsort(v, n, posicao);
	}
}

int main(){
	int n;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	int v[n];
	lerVetor(v, n);
	radixsort(v, n);
	imprimirVetor(v, n);
	return 0;
}
