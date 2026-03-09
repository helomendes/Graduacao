#include <stdio.h>
#define MAX 1024

int lerVetor(int V[], int *n)
{
	printf("Qual o tamanho do vetor? ");
	scanf("%d", &*n);
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

void copiarVetor(int n, int V[], int W[])
{
	for(int i = 0; i < n; i++)
		V[i] = W[i];
}

void contador(int n, int V[])
{
	int M[n], L[n], cont = n, ind, i = 0, j = 0;
	L[0] = 0;
	copiarVetor(n, M, V);
	while(cont)
	{
		ind = M[0];
		j = 0;
		for (i = 0; i < cont; i++)
		{
			if (M[i] != ind)
				L[j++] = M[i];
		}
		printf("Elemento %d apareceu %d vezes\n", ind, cont - j);
		cont = j;
		for (i = 0; i < cont; i++)
			M[i] = L[i];
	}
}

int main()
{
	int V[MAX], W[MAX], n;
	lerVetor(V, &n);
	contador(n, V);
	return 0;
}
