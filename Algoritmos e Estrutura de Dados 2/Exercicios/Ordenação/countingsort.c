#include <stdio.h>
#include <stdlib.h>

void imprime(int v[], int tam){
	for(int i = 0; i < tam; i++)
		printf("[%d] = %d\n", i, v[i]);
}

void ler(int v[], int tam){
	for(int i = 0; i < tam; i++){
		printf("vetor[%d] = ", i);
		scanf("%d", &v[i]);
	}
}

void countingsort(int v[], int n, int k){
	int c[k+1];
	int r[n];
	int i, j;

	for(i = 0; i <= k; i++)
		c[i] = 0;

	for(j = 0; j < n; j++)
		c[v[j]] = c[v[j]] + 1;

	for(i = 1; i <= k; i++){
		c[i] = c[i] + c[i-1];
	}

	for(i = 0; i <= k; i++)
		c[i] = c[i] - 1;

	for(j = n-1; j >= 0; j--){
		r[c[v[j]]] = v[j];
		c[v[j]] = c[v[j]] - 1;
	}

	for(int h = 0; h < n; h++)
		v[h] = r[h];
}

int main(){
	printf("\tCounting Sort\nAo usar este algoritmo, você garante que todos os elementos do vetor a ser passado são valores Naturais (incluindo o 0).\n");
	
	int n;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	int vetor[n];
	ler(vetor, n);
	
	int k;
	printf("Maior elemento do vetor: ");
	scanf("%d", &k);

	countingsort(vetor, n, k);
	
	imprime(vetor, n);
	
	return 0;
}
