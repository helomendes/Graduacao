#include <stdio.h>

void maior(int *pa, int *pb){
	printf("Insira dois valores inteiros: ");
	scanf("%d %d", &*pa, &*pb);
	int m;
	if (*pa >= *pb)
		m = *pa;
	else
		m = *pb;
	printf("O maior valor é %d\n", m);
}

int main(){
	int a, b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;
	maior(&*pa, &*pb);
	return 0;
}
