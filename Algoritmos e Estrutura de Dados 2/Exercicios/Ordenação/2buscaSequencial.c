#include <stdio.h>
#define TAM 10

int buscaSequencial(int x, int v[], int a, int b){
	if (a > b)
		return (a-1);
	if (v[b] <= x)
		return b;
	return buscaSequencial(x, v, a, b-1);
}

int main(){
	int v[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a = 0;
	int b = 9;
	int x;
	scanf("%d", &x);
	if (v[buscaSequencial(x, v, a, b)] == x)
		printf("sim\n");
	else
		printf("não\n");
	return 0;
}

