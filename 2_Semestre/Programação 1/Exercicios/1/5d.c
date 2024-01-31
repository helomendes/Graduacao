#include <stdio.h>
#define MAX 1024

int maior(int vetor[], int n)
{
	int maior = vetor[0];
	for (int i = 1; i < n; i++)
	{
		if (vetor[i] > maior)
			maior = vetor[i];
	}
	return maior;
}

int menor(int vetor[], int n)
{
	int menor = vetor[0];
	for (int i = 1; i < n; i++)
	{
		if (vetor[i] < menor)
			menor = vetor[i];
	}
	return menor;
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

	printf("O maior elemento do vetor é: %d\n", maior(vetor, n));
	printf("O menor elemento do vetor é: %d\n", menor(vetor, n));

	return 0;
}

