#include <stdio.h>

int euclides(int a, int b)
{
	if (b < 1)
		return a;
	if (a < 1)
		return b;
	return euclides(b, a%b);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", euclides(a, b));
	return 0;
}
 
