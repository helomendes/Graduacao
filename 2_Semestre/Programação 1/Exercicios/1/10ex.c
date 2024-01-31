#include <stdio.h>
#define MAX 1024

int lerVetor(int V[], int *n)
{
	printf("Insira um inteiro: ");
	scanf("%d", &*n);

	if (*n > MAX)
	{
		printf("Valor fornecido excede o valor máximo.");
		return 0;
	}
	for(int i = 0; i < *n; i++)
	{
		printf("Insira o vetor %d: ", i);
		scanf("%d", &V[i]);
	}
	return 0;
}

int pares (int V[], int n)
{
	int pares = 0;
	for (int i = 0; i < n; i++)
	{
		if (V[i] % 2 == 0)
			pares++;
	}
	return pares;
}

int impares (int V[], int n)
{
	int impares = 0;
	for (int i = 0; i < n; i++)
	{
		if (V[i] % 2 != 0)
			impares++;
	}
	return impares;
}

int main()
{
	int V[MAX], n;
	lerVetor(V, &n);
	printf("Existem %d elementos pares e %d elementos ímpares\n", pares(V, n), impares(V, n));
	return 0;
}
