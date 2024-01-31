#ifndef AUXILIARES_H_
#define AUXILIARES_H_

void lerVetor(int vetor[], int tam);

void imprimirVetor(int vetor[], int tam);

void trocar(int vetor[], int a, int b);

int bsequencial(int vetor[], int tam, int valor, int* numComparacoes);

int buscab(int vetor[], int a, int b, int valor, int* numComparacoes);

int inserir(int vetor[], int tam);

int minimo(int vetor[], int a, int b);

int selecs(int vetor[], int a, int b, int *cont);

int merge(int vetor[], int a, int m, int b);

int merges(int vetor[], int a, int b, int *cont);

void copiar(int vetor[], int u[], int a, int b);

int particionar(int v[], int a, int b, int *cont);

int quicks(int v[], int a, int b, int *cont);

int indicePai(int i);

int indiceFilhoEsquerdo(int i);

int indiceFilhoDireito(int i);

int maxheapify(int v[], int i, int tam, int *comp);

void construirMaxheap(int v[], int tam, int *comp);

void heaps(int vetor[], int tam, int *comp);

void vetorAleatorio(int vetor[], int tamVetor);

void vetorInverso(int vetor[], int tamVetor);

void vetorOrdenado(int vetor[], int tamVetor);

#endif // AUXILIARES_H_
