#include <stdio.h>
#define MAX 1024

void copiaInversa(int vetor[], int wetor[], int n)
{
	for (int i = 0; i  < n; i++)
		wetor[n-(1+i)] = vetor[i];
	for (int i = 0; i  < n; i++)
		printf("vetor inverso W[%d] = %d\n", i, wetor[i]);
}

int main()
{
	int n, vetor[MAX], wetor[MAX];
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
		scanf("%d", &vetor[i]);
	}
	copiaInversa(vetor, wetor, n);
	return 0;
}


