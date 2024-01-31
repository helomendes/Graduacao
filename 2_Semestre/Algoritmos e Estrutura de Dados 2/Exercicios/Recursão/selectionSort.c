#include <stdio.h>
#define TAM 6

void trocar(int v[], int x, int y){
	int aux = v[x];
	v[x] = v[y];
	v[y] = aux;
}

int minimo(int v[], int a, int b){
	int min = a;
	for(int i = a+1; i<=b; i++)
		if(v[i] < v[min])
			min = i;
	return min;
}

void selectionSort(int v[], int a, int b){
	while(a < b){
		int min = minimo(v, a, b);
		trocar(v, a, min);
		a = a + 1;
	}
}

int main(){
	int v[TAM];
	for(int i = 0; i<TAM; i++)
		scanf("%d", &v[i]);
	selectionSort(v, 0, TAM-1);
	for(int i = 0; i<TAM; i++)
		printf("%d\t", v[i]);
	return 0;
}
