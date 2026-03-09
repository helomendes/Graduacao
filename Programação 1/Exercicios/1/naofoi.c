#include <stdio.h>
#define MAX 1024

//o que eu preciso fazer, em etapas:
//1. ler o vetor
//2. contar quantas vezes cada elemento aparece
//3. imprimir quantas vezes cada elemento apareceu

int lerVetor(int V[], int *n)
{
	printf("Qual o tamanho do vetor?\t");
	scanf("%d", &*n); //quero colocar um ponteiro em n
	if (*n > MAX)
	{
		printf("Valor excede o tamanho máximo.");
		return 0;
	}
	for(int i = 0; i < *n; i++)
	{
		printf("Insira o vetor %d: ", i);
		scanf("%d", &V[i]);
	}
	return 0;
}

int repete(int x, int V[], int n)
{
	int cont = 0;
	for(int i = 0; i < n; i++)
	{
		if (x == V[i])
			cont++;
	}
}

int main()
{
	int V[MAX], n, cont[MAX];
	lerVetor(V, &n);
	for (int j=0; j<n; j++)
	{
		cont[j]=repete(V[j], V, n);
		printf("%d\n", cont[j]);
	}
	return 0;
}
