#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 10

void preencherAleatorio(int vet[], int numPos)
{
	int i;
	for(i = 0; i < numPos; i++)
		vet[i] = rand()%100;
}

void imprimirVetor(int vet[], int numPos)
{
	for (int i = 0; i < numPos; i++)
		printf("%d", vet[i]);
}

int minimoVetor(int vetor[], int tamanhoVetor)
{
	int j = 0;
	int minimo = 0;
	while (j < tamanhoVetor-1)
	{
		j = j+1;
		if (vetor[j] < vetor[minimo])
			minimo = j;
	}
	return minimo;
}

int main()
{
	int vetor[10];
	int idxMenor;
	srand(time(NULL));
	preencherAleatorio(vetor, M);
	imprimirVetor(vetor, M);
	idxMenor = minimoVetor(vetor, M);
	printf("%d %d\n", idxMenor, vetor[idxMenor]);
	return 0;
}
