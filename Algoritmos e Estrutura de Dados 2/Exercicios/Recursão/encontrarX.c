#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int encontrarX(int vetor[], int a, int b, int x){
	if (a>b)
		return -1;
	if (vetor[a] > x || vetor[b] < x)
		return -1;
	if (a == b && vetor[a] != x)
		return -1;
	if (vetor[a] == x)
		return a;
	if (vetor[b] == x)
		return b;
	return(encontrarX(vetor, a+1, b-1, x));
}

void selectionSort(int vetor[], int tamanho){
    int idxMenorElemento;
    int aux;
    for(int i =0; i < tamanho; i++){
        idxMenorElemento = i;
        for(int j = i+1; j < tamanho; j++){
            if(vetor[idxMenorElemento] > vetor[j])
                idxMenorElemento = j;
        }
        if(idxMenorElemento != i){
            aux = vetor[i];
            vetor[i] = vetor[idxMenorElemento];
            vetor[idxMenorElemento] = aux;
        }
    }
}

void preencherAleatorio(int vet[], int numPos, int maxVal){
	int i;
	for(i = 0; i < numPos; i++)
		vet[i] = rand()%maxVal;
}

void imprimeVetor(int vetor[], int tamanho){
    for(int i=0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int vetor[N];

    srand(time(0));

    preencherAleatorio(vetor, N, 100);
    selectionSort(vetor, N);

    printf("Vetor ordenado: ");
    imprimeVetor(vetor, N);

    int a = 0, b = N;
    int x;
    printf("Insira o valor de x: ");
    scanf("%d", &x);
    if (encontrarX(vetor, a, b, x) == -1)
	    printf("Não.\n");
    else
	    printf("Índice %d\n", encontrarX(vetor, a, b, x));

    return 0;
}
