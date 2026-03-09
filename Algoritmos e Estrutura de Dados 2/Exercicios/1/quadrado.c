#include <stdio.h>

int quantosDigitos(int num, int c)
{
	if (num < 10)
		c = 1;
	else
	{
		while (num > 0)
		{
			num = num / 10;
			c++;
		}
	}
	return c;
}

int main()
{
	int n, quad, aux, auxq, i = 0, d = 0;
	printf("Digite um número: ");
	scanf("%d", &n);
	aux = n;
	quad = n*n;
	i = quantosDigitos(quad, i);
	d = quantosDigitos(n, d);
	while(n > 0)
	{
		auxq = quad % 10;
		aux = n % 10;
		quad = quad / 10;
		n = n / 10;
		if (auxq == aux)
			i--;
		else
			i = d+2;
	}
	if (i == d + 2)
		printf("Não tem\n");
	else
		printf("Tem\n");
	return 0;
}
