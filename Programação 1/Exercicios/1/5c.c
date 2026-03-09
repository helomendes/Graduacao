#include <stdio.h>
#define MAX 1024

int soma(int vetor[], int n)
{
	int soma = 0;
	for (int i = 0; i < n; i++)
		soma = soma + vetor[i];
	return soma;
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

	float media = soma(vetor, n)/(float)n;

	printf("A média entre os elementos do vetor é: %.2f\n", media);

	return 0;
}
