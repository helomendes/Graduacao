#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int retornaM(int v[], int a, int b, int x, int y){
	if(a>b)
		return -1;
	if(v[a] > x && v[a] < y)
		return a;
	return(retornaM(v,a+1,b,x,y));
}

void preencherAleatorio(int v[], int maxVal){
	int i;
	for(i = 0; i < TAM; i++)
		v[i] = rand()%maxVal;
}

void imprimeVetor(int v[]){
    for(int i=0; i < TAM; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
	int v[TAM];
	int maxVal;
	int x, y;
	int a = 0;
	int b = TAM;
	printf("Insira o valor máximo do vetor: ");
	scanf("%d", &maxVal);
	preencherAleatorio(v, maxVal);
	imprimeVetor(v);
	printf("Insira x e y: ");
	scanf("%d %d", &x, &y);
	if (retornaM(v,a,b,x,y) == -1)
		printf("Não existe.\n");
	else
		printf("vetor de índice %d\n", retornaM(v, a, b, x, y));
	return 0;
}
