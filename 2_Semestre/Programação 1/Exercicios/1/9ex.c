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
	return 1;
}

int escreverVetor(int n, int V[])
{
	for(int i = 0; i < n; i++)
		printf("%d\t", V[i]);
	printf("\n");
	return 0;
}

void ordenarVetor(int n, int V[])
{
	int menor, aux, j;
	for (int i = 0; i < n-1; i++)
	{
		menor = i;
		for (int j = i+1; j < n; j++)
		{
			if (V[j] < V[menor])
				menor = j;
		}
	aux = V[i];
	V[i] = V[menor];
	V[menor] = aux;
	}
}

int contarElementos(int n, int V[], int i)
{
	int iguais = 0;
	for (int j = 0; j < n; j++)
	{
		if (V[j] == V[i])
			iguais++;
	}
	return iguais;
}

int elementosRepetidos(int n, int V[])
{
	int i = 0, j = 0, W[n];
	ordenarVetor(n, V);
	while(i < n-1)
	{
		if (V[i] == V[i+1])
		{
			W[j] = V[i];
			i += contarElementos(n, V, i);
			j++;
		}
		else
			i++;
	}
	printf("Existem %d números repetidos:\n", j);
	escreverVetor(j, W);
	return 0;
}

int main()
{
	int V[MAX], n;
	if (lerVetor(V, &n) == 1)
	{
		escreverVetor(n, V);
		elementosRepetidos(n, V);
	}
	return 0;
}
