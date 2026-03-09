#include <stdio.h>
#include <math.h>

int main ()
{
	int a, b, c;
        float x1, x2, raiz;
	printf("insira os valores de a, b e c: ");
	scanf("%d %d %d", &a, &b, &c);
	raiz = sqrt( b*b - 4*a*c );
	x1 = (-1*b + raiz)/2;
	x2 = (-1*b - raiz)/2;
	printf("raízes: %.2f e %.2f\n", x1, x2);
	return 0;
}


	printf("Vetor original:\n");