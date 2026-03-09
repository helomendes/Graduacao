#include <stdio.h>

int fat(unsigned int n)
{
	if (n == 0)
		return 1;
	return n*fat(n-1);
}

int main()
{
	unsigned int valFat, res;
	printf("Digite o valor para calcular: ");
	scanf("%d", &valFat);
	res = fat(valFat);
	printf("%u\n", res);
	return 0;
}
