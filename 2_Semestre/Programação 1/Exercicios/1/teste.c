#include <stdio.h>
#define MAX 1024

int lerVetor(int V[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("Insira o vetor %d: ", i);
		scanf("%d", &V[i]);
	}
	return 0;
}
int escreverVetor(int n, int vetor[])
{
	for(int i = 0; i < n; i++)
		printf("vetor[%d] = %d\n", i, vetor[i]);
	return 0;
}

int concatenar(int V[], int M[], int W[], int n)
{
	for(int i = 0; i < n; i++)
		W[i] = V[i];
	for(int i = 0; i < n; i++)
		W[n+i] = M[i];
	for(int i = 0; i < 2*n; i++)
		printf("Vetor[%d] = %d\n", i, W[i]);
}

int main()
{
	int n, V[MAX], M[MAX], W[MAX];
	printf("Insira um inteiro: ");
	scanf("%d", &n);
	if (n > MAX)
	{
		printf("Valor fornecido excede o valor máximo.");
		return 0;
	}
	lerVetor(V, n);
	printf("Próximo vetor.\n");
	lerVetor(M, n);
	printf("Primeiro vetor:\n");
	escreverVetor(n, V);
	printf("Segundo vetor:\n");
	escreverVetor(n, M);
    printf("Vetor concatenado:\n");
	concatenar(V, M, W, n);
	return 0;
}