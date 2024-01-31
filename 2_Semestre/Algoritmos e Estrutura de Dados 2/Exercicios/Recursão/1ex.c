#include <stdio.h>

int potencia(int x, int n)
{
	int pot;
	if (n==0)
		return 1;
	pot = x*potencia(x, n-1);
	return pot;
}

int main ()
{
	int x, n, res;
	scanf("%d %d", &x, &n);
	res = potencia(x, n);
	printf("%d\n", res);
	return 0;
}
