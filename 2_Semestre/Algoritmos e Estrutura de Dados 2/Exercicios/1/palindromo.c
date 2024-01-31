#include <stdio.h>
#include <math.h>

int ehPar(int n, int c)
{
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	if (c / 2 == 0)
		return 0;
	else
		return 1;
}

int palindromo(int n, int c, int vetor[], int wetor[], int i)
{
	int x = 0;
	if (ehPar(n, c) == 0)
	{
		while (x < c/2)
		{
			vetor[i] = n % 10;
			n = n / 10;
			x++;
			i++;
		}
		x = 10^(c-1);
		i = 0;
		while (x > c/2)
		{
			wetor[i] = n % 10;
			n = n / 10;
			x--;
			i++;
		}
		while (i <= 99)
		{
			if (wetor[i] != vetor[i])
				break;
			else
				c = 0;
			i++;
		}
	}
	else
	{
		while (x < c/2)
		{
			vetor[i] = n % 10;
			n = n / 10;
			x++;
			i++;
		}
		x = 10^(c-1);
		i = 0;
		n = n / 10;
		while (x > c/2)
		{
			wetor[i] = n % 10;
			n = n / 10;
			x--;
			i++;
		}
		i = 0;
		while (i <= 99)
		{
			if (wetor[i] != vetor[i])
				break;
			else
				c = 0;
			i++;
		}
	}
	return c;
}

int main()
{
	int n, c = 0, vetor[99], wetor[99], i = 0;
	printf("insira um número: ");
	scanf("%d", &n);
	if (palindromo(n, c, vetor, wetor, i) == 0)
		printf("é um palíndromo\n");
	else
		printf("não é um palíndromo\n");
	return 0;
}
