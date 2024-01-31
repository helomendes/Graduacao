#include <stdio.h>

void lerVetor(int vetor[], int N){
	for(int i = 0; i<N; i++){
		printf("Vetor[%d] = ", i);
		scanf("%d", &vetor[i]);
	}
	printf("\n");
}

void imprimirVetor(int vetor[], int N){
	for(int i = 0; i<N; i++)
		printf("Vetor[%d] = %d\n", i, vetor[i]);
}

int merge(int vetor[], int N){
	for(int i = N/2; i<N; i++)
		for(int j = 0; j<N/2; j++)
			if(vetor[j] > vetor[i]){
				int aux = vetor[i];
				for(int k = i; k>j; k--)
					vetor[k] = vetor[k-1];
				vetor[j] = aux;
			}
}

int main(){
	int N;
	printf("Insira o tamanho do vetor: ");
	scanf("%d", &N);
	int vetor[N];
	lerVetor(vetor, N);
	merge(vetor, N);
	imprimirVetor(vetor, N);
	return 0;
}
