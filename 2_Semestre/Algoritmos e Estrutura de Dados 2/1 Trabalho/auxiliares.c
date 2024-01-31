#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include "auxiliares.h"

void lerVetor(int vetor[], int tam){
	printf("Insira os elementos do vetor:\n");
	for(int i = 0; i<tam; i++){
		printf("vetor[%d] = ", i);
		scanf("%d", &vetor[i]);
	}
}

void imprimirVetor(int vetor[], int tam){
	printf("Imprimindo o vetor:\n");
	for(int j = 0; j<tam; j++)
		printf("vetor[%d] = %d\n", j, vetor[j]);
}

void trocar(int vetor[], int a, int b){
	int x = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = x;
}

int bsequencial(int vetor[], int tam, int valor, int* numComparacoes){
	if(tam <= 0)
		return tam-1;
	*numComparacoes = *numComparacoes + 1;
	if(vetor[tam-1] <= valor)
		return (tam-1);
	return bsequencial(vetor, tam-1, valor, &*numComparacoes);
}

int buscab(int vetor[], int a, int b, int valor, int* numComparacoes){
	if (a > b)
		return a-1;
	int m = (a+b)/2;
	*numComparacoes = *numComparacoes + 1;
	if (valor < vetor[m])
		return buscab(vetor, a, m-1, valor, &*numComparacoes);
	return buscab(vetor, m+1, b, valor, &*numComparacoes);
}

int inserir(int vetor[], int tam){
	int comp = 0;
	int p = buscab(vetor, 0, tam-1, vetor[tam-1], &comp);
	int i = tam-1;
	while(i > p + 1){
		trocar(vetor, i, i-1);
		i--;
	}
	return comp;
}

int minimo(int vetor[], int a, int b){
	int i = a;
	int min = a;
	while (i < b){
		i = i + 1;
		if (vetor[i] < vetor[min])
			min = i;
	}
	return min;
}

int selecs(int vetor[], int a, int b, int *cont){
	if (a >= b)
		return 0;
	trocar(vetor, a, minimo(vetor, a, b));
	*cont = *cont + b - a;
	return selecs(vetor, a+1, b, &*cont);
}

int merge(int vetor[], int a, int m, int b){
	if (a >= b)
		return 0;
	int k = 0;
	int i = a;
	int j = m+1;
	int *u = malloc((b-a+1) * sizeof(int));
	int p;
	while(k <= b-a){
		if (j > b || (i <= m && vetor[i] <= vetor[j])){
			p = i;
			i++;
		}
		else{
			p = j;
			j++;
		}
		u[k] = vetor[p];
		k++;
	}
	copiar(vetor, u, a, b);
	free(u);
	return k;
}

int merges(int vetor[], int a, int b, int *cont){
	if(a >= b)
		return 0;
	int m = ((a+b)/2);
	*cont = merges(vetor, a, m, &*cont);
	*cont = *cont + merges(vetor, m+1, b, &*cont);
	return *cont + merge(vetor, a, m, b);
}

void copiar(int vetor[], int u[], int a, int b){
	for(int i = 0; i<= b-a; i++)
		vetor[a+i] = u[i];
}

int particionar(int v[], int a, int b, int *cont){
	int x = v[b]; //pivô
	int m = a;
	for(int i = a; i<b; i++){
		*cont = *cont + 1;
		if(v[i] <= x){
			trocar(v, m, i);
			m++;
		}
	}
	trocar(v, m, b);
	return m;
}

int quicks(int v[], int a, int b, int *cont){
	if(a>=b)
		return 0;
	int m = particionar(v, a, b, &*cont);
	quicks(v, a, m-1, &*cont);
	quicks(v, m+1, b, &*cont);
	return *cont;
}

int indicePai(int i){
	if (i/2 == 0)
		return (i >> 1) -1;
	return (i >> 1);
}

int indiceFilhoEsquerdo(int i){
	return (i << 1) + 1;
}

int indiceFilhoDireito(int i){
	return (i << 1) + 2;
}

int maxheapify(int v[], int i, int tam, int *comp){
	int l = indiceFilhoEsquerdo(i);
	int r = indiceFilhoDireito(i);
	int maior;
	if (l <= tam && v[l] > v[i])
		maior = l;
	else
		maior = i;
	if (r <= tam && v[r] > v[maior])
		maior = r;
	*comp = *comp + 2;
	if (maior != i){
		trocar(v, i, maior);
		maxheapify(v, maior, tam, &*comp);
	}
	return 0;
}

void construirMaxheap(int v[], int tam, int *comp){
	for(int i = (tam/2) - 1; i >= 0; i--)
		maxheapify(v, i, tam-1, &*comp);
}

void heaps(int vetor[], int tam, int *comp){
	construirMaxheap(vetor, tam, &*comp);
	for(int i = (tam-1); i>=1; i--){
		trocar(vetor, 0, i);
		maxheapify(vetor, 0, i-1, &*comp);
	}
}

void vetorAleatorio(int vetor[], int tamVetor){
	for(int i = 0; i<tamVetor; i++){
		vetor[i] = rand() % 1000;
	}
}

void vetorInverso(int vetor[], int tamVetor){
	for(int i = tamVetor-1; i >= 0; i--){
		int ind = -1*(i-tamVetor+1);
		vetor[ind] = i;
	}
}

void vetorOrdenado(int vetor[], int tamVetor){
	for(int i = 0; i<tamVetor; i++)
		vetor[i] = i;
}
