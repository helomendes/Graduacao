#include <stdio.h>

void soma(int *pa, int *pb){
	printf("Insira dois valores inteiros: ");
	scanf("%d %d", &*pa, &*pb);
	int soma = *pa + *pb;
	printf("%d + %d = %d\n", *pa, *pb, soma);
}

int main(){
	int a, b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;
	soma(&*pa, &*pb);
	return 0;
}
