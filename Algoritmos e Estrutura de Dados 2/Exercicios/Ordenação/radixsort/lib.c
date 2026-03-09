#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void lerVetor(int v[], int tam){
	for(int i = 0; i < tam; i++){
		printf("vetor[%d] = ", i);
		scanf("%d", &v[i]);
	}
}

void imprimirVetor(int v[], int tam){
	for(int i = 0; i < tam; i++)
		printf("[%d] = %d\n", i, v[i]);
}

void countingsort(int v[], int n, int posicao){	
	int c[10];
	int r[n];
	int i, j;

	int div = 1;
	for(i = 0; i < posicao; i++)
		div = div * 10;

	for(i = 0; i < 10; i++)
		c[i] = 0;

	for(j = 0; j < n; j++)
		c[v[j]%div] += 1;

	for(i = 1; i < 10; i++){
		c[i] = c[i] + c[i-1];
	}

	for(i = 0; i < 10; i++)
		c[i] = c[i] - 1;

	for(j = n-1; j >= 0; j--){
		r[c[v[j]%div]] = v[j];
		c[v[j]%div] = c[v[j]%div] - 1;
	}

	for(int h = 0; h < n; h++)
		v[h] = r[h];
}
