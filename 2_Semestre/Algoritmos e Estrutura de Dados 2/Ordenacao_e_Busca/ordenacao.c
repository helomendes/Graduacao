#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "ordenacao.h"

#include <string.h>

void getNome(char nome[]){
	strncpy(nome, "Heloisa Benedet Mendes", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20221248;
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	int indice = bsequencial(vetor, tam, valor, &*numComparacoes);
	if(vetor[indice] == valor)
		return indice;
	return -1;

}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	int a = 0;
	int b = tam - 1;
	int indice = buscab(vetor, a, b, valor, &*numComparacoes);
	if (valor == vetor[indice])
		return indice;
	return -1;
}

int insertionSort(int vetor[], int tam){	
	int comparacoes = 0;
	if (tam <= 1)
		return 0;
	comparacoes = comparacoes + insertionSort(vetor, tam-1);
	comparacoes = comparacoes + inserir(vetor, tam);
	return comparacoes;
}

int selectionSort(int vetor[], int tam){
	int a = 0;
	int b = tam-1;
	int contador = 0;
	selecs(vetor, a, b, &contador);
	return contador;
}

int mergeSort(int vetor[], int tam){
	int a = 0;
	int b = tam-1;
	int cont = 0;
	merges(vetor, a, b, &cont);
	return cont;
}

int quickSort(int vetor[], int tam){
	int a = 0;
	int b = tam-1;
	int contador = 0;
	contador = quicks(vetor, a, b, &contador);
	return contador;
}

int heapSort(int vetor[], int tam){
	int comp = 0;
	heaps(vetor, tam, &comp);
	return comp;
}
