#include <stdio.h>
#define MAX 1024
int main()
{
	int n, vetor[MAX];
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
	printf("Vetor original:\n");
	for (int i = 0; i < n; i++)
		printf("vetor[%d] = %d\n", i, vetor[i]);
	printf("Vetor ao contrário:\n");
	for (int i = n-1; i >= 0; i--)
		printf("vetor[%d] = %d\n", i, vetor[i]);
	return 0;
}
