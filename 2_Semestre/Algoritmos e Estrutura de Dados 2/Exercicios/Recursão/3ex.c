#include <stdio.h>

int fibonacci(int n)
{
	int termo;
	if (n <= 1)
		return n;
	termo = fibonacci(n-1) + fibonacci(n-2);
	return termo;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fibonacci(n));
	return 0;
}
