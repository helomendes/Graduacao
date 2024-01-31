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

struct unit{
	float dado;
	struct lista *prox;
};

struct lista{
	struct unit *cabeca;
};

int inserir(int vetor[], int tam){
	int comp = 0;
	int p = buscab(vetor, 0, tam-1, vetor[tam-1], &comp);
	int i = tam-1;
	while(i > p + 1){
		trocar(vetor, i, i-1);
		i--;
	}
	return comp;
}

int insertionSort(int vetor[], int tam){
	int comparacoes = 0;
	if (tam <= 1)
		return 0;
	comparacoes = comparacoes + insertionSort(vetor, tam-1);
	comparacoes = comparacoes + inserir(vetor, tam);
	return comparacoes;
}

void bucketSort(int v[], int n){
	struct lista *bucket;
	bucket = malloc(n*sizeof(struct unit));

	int i;
	int j = 1;

	for(i = 0; i < n; i++)
		b[i] = NULL;

	for(i = 0; i < n; i++){
		if(b[i] = NULL)
			b[n*v[i]] = v[i];
		else


	for(i = 0; i < n; i++){
		isertionSort
		j = j + tamanho(b[i]);
}

int main(){
	int n;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	int v[n];
	ler(v, n);


	return 0;
}
