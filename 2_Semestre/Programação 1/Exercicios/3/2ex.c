#include <stdio.h>

int descompressao(long int var, int vetor[])
{
	int u, d, c;
	for (int i=0; i < 3; i++)
	{
		u = var % 10;
		var = var / 10;
		d = var % 10;
		var = var / 10;
		c = var % 10;
		var = var /10;
		vetor[i] = c*100 + d*10 + u;
	}
	return 0;
}

int main ()
{
	long int valor;
	int vetor[3];
	scanf("%ld", &valor);
	descompressao(valor, vetor);
	for (int i=2; i >= 0; i--)
		printf("%d\t", vetor[i]);
	return 0;
}
