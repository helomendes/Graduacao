#include <stdio.h>
#define TAM 10

int buscaBinaria(int x, int v[TAM], int a, int b){
	int m;
	if (a > b)
		return (a-1);
	m = (a+b)/2;
	if (x < v[m])
		return buscaBinaria(x, v, a, m-1);
	return buscaBinaria(x, v, m+1, b);
}

int main(){
	int v[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a = 0;
	int b = 9;
	int x;
	scanf("%d", &x);
	printf("%d\n", buscaBinaria(x, v, a, b));
	return 0;
}
