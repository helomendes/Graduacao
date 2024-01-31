#include <stdio.h>
#define MAX 1024

//tenho que colocar ponteiros aqui
int n = 0;
int V[MAX];

int ordenacao()
{
	int aux, c = 0;
	while(c < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (V[i+1] < V[i])
			{
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = V[i];
			}
		}
		c++;
	}
	return 0;
}

//função que le o tamanho do vetor e o proprio vetor
int entradaDeDados()
{
	printf("Insira um inteiro: ");
	scanf("%d", &n);

	if (n > MAX)
	{
		printf("Valor fornecido excede o valor máximo.");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		printf("Insira um valor pra o vetor de índice %d: ", i);
		scanf("%d", &V[i]);
	}
	return 0;
}

int compara(int x, int y)
{
	if (x == y)
		return 1;
	return 0;
}

//conta quantas vezes um numero aparece no vetor
int contador(int V[], int x, int n)
{
	int cont = 0;
	for(int i = 0; i < n; i++)
	{
		if (V[i] == x)
			cont = cont +1;
	}
	return cont;
}

int main()
{
	int cont[MAX];
	entradaDeDados;
	for (int i = 0; i < n; i++)
		printf("V[%d] = %d\n", i, V[i]);
	ordenacao(V, n);
	printf("Agora ordenado\n");
	for (int i = 0; i < n; i++)
		printf("V[%d] = %d\n", i, V[i]);
	
	return 0;
}
