#include "libconjunto.h"
#include <stdio.h>
#include <stdlib.h>
#define N 100
void ordena(int vetor[], int tam){
	for (int i = 0; i < tam; i++){
        	for (int j = i; j < tam; j++){
            		if (vetor[i] > vetor[j]){
                		int temp = vetor[i];
                		vetor[i] = vetor[j];
                		vetor[j] = temp;
            		}	
        	}
    	}
}

int preencher(int vetor[]){
	int i = 0;
	printf("Insira o vetor, digite um número negativo para encerrar.\n");
	for(i; i < N; i++){
		scanf("%d", &vetor[i]);
		if (vetor[i] < 0)
			return 0;
	}
	printf("\n");
	return 0;
}

int ehvazio(int vetor[]){
	for(int i = 0; i < N; i++){
		if(vetor[i] >= 0)
			return 1;
	}
		return 0;
}

int contador(int vetor[]){
	int cont = 0;
	for(int i = 0; i < N; i++){
		if (vetor[i] >= 0)
			cont = cont + 1;
		else{
			printf("Tamanho = %d\n", cont);
			return cont;
		}
	}
	printf("Tamanho = %d\n", cont);
	return cont;
}

void imprimirVetor(int vetor[], int n){
	for(int i = 0; i < n; i++)
		if(vetor[i] > -1)
			printf("[%d]\t", vetor[i]);
	printf("\n");
}

void preencherAleatorio(int M[]){
	for(int i = 0; i < N; i++)
		M[i] = rand() %100;
}

void uniao(int vetor[], int M[], int U[], int cont){
	int j = 0;
	int total = N + cont;
    	for (int i = 0; i < N; i++)
        	U[i] = M[i];
    	for (int l = N; l < total; l++) {
        	U[l] = vetor[j];
        	j++;
    	}
	ordena(U, total);
	for(int i=0; i<total; i++){
		if(U[i] == U[i+1]){
			for(int k = i; k<total; k++)
				U[k] = U[k+1];
			total = total-1;
		}
		if(i > 0){
			if(U[i] == U[i-1]){
				for(int k = i-1; k<total; k++)
					U[k] = U[k+1];
				total = total - 1;
			}
		}
	}
	printf("\nVetor união:\n");
	imprimirVetor(U, total);
}

void interseccao(int vetor[], int M[], int I[], int tam){
    	int tamI = -1;
	for (int i = 0; i < tam; i++){
		for(int j = 0; j < N; j++){
        		if (vetor[i] == M[j]){
            			tamI++;
            			I[i] = vetor[i];
			}
        	}
   	}
    	if (tamI == 0)
        	printf("\nVetor intersecção vazio\n");
    	else{
		printf("\nVetor intersecção:\n");
        	imprimirVetor(I, tamI);
	}
}

void limparVetor(int vetor[], int n){
	for(int i = 0; i<n; i++)
		vetor[i] = -1;
}
