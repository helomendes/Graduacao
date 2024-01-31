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
	for (int i = 0; i < n; i++)
		printf("vetor[%d] = %d\n", i, vetor[i]);
	return 0;
}
