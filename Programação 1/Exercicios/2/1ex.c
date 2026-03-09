#include <stdio.h>

int main(){
	int a, b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;
	printf("Insira dois valores inteiros: ");
	scanf("%d %d", &*pa, &*pb);
	int soma = *pa + *pb;
	printf("%d + %d = %d\n", *pa, *pb, soma);
	return 0;
}
