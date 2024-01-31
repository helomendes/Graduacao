#include <stdio.h>
#define MAX 1024

int main()
{
	int V[MAX], W[MAX], M[MAX], n;

	printf("Insira o tamanho do vetor: ");
	scanf("%d", &n);

	if (n > 1024)
	{
		printf("O tamanho excede o valor máximo.\n");
		return 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("Insira o elemento de índice %d do primeiro vetor: ", i);
		scanf("%d", &V[i]);
	}

	for (int i = 0; i < n; i++)
	{
		printf("Insira o elemento de índice %d do segundo vetor: ", i);
		scanf("%d", &W[i]);
	}

	for (int i = 0; i < n; i++)
	{
		M[i] = V[i]*W[i];
		printf("vetor produto M[%d] = %d\n", i, M[i]);
	}
		return 0;
}
