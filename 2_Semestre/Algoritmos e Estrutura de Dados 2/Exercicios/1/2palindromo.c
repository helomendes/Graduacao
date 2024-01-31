#include <stdio.h>

int main()
{
	int n, aux, reverso = 0;
	printf("Digite um número: ");
	scanf("%d", &n);
	aux = n;
	while (aux != 0)
	{
		reverso = (reverso * 10) + (aux % 10);
		aux = aux / 10;
	}
	if (reverso == n)
		printf("é palíndromo\n");
	else
		printf("não é palíndromo\n");
	return 0;
}
