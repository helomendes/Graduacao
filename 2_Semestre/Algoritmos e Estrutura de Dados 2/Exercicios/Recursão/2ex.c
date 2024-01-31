#include <stdio.h>
#define TAM 1024

void lerVetor(int v[], int b)
{
	for (int i = 0; i < b; i++)
		scanf("%d", &v[i]);
}

int somaVetor(int v[], int a, int b)
{
	int soma = 0;
	if (a==b)
		return v[a];
	soma = v[b] + somaVetor(v, a, b-1);
	return soma;
}

int main()
{
	int v[TAM], a = 0, b, soma;
	scanf("%d", &b);
	if (b > TAM)
	{
		printf("Valor inválido.\n");
		return 0;
	}
	lerVetor(v, b);
	printf("%d\n", somaVetor(v, a, b));
	return 0;
}
