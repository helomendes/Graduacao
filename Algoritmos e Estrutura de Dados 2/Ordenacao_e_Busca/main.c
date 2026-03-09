#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliares.h"

#define MAX_CHAR_NOME 50

int main(){
	char nome[MAX_CHAR_NOME];
	
	int indxBusca;
	int numComp = 0;

	long int tamVetor = 1000;
	int *vetor = malloc(tamVetor * sizeof(int));
	if (vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.\n");
		return 1;
	}

	clock_t start, end;
	double total;

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	printf("\n\t\tAlgoritmos de busca\n");

	vetorOrdenado(vetor, tamVetor);
	start = clock();
	indxBusca = buscaSequencial(vetor, tamVetor, 3, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Busca Sequencial\n");
	printf("\tíndice: %d\n\tNúmero de comparações:  %d\n\ttempo: %f\n", indxBusca, numComp, total);

	numComp = 0;
	start = clock();
	indxBusca = buscaBinaria(vetor, tamVetor, 3, &numComp);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nBusca Binaria\n");
	printf("\tíndice: %d\n\tNúmero de comparações:  %d\n\ttempo: %f\n", indxBusca, numComp, total);


	printf("\n\t\tAlgoritmos de ordenação\n");

	printf("Insertion Sort:\n");
	printf("Vetor aleatório\n");
	vetorAleatorio(vetor, tamVetor);
	start = clock();
	numComp = insertionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor inverso\n");
	vetorInverso(vetor, tamVetor);
	start = clock();
	numComp = insertionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor ordenado\n");
	vetorOrdenado(vetor, tamVetor);
	start = clock();
	numComp = insertionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);

	printf("\nSelection Sort:\n");
	printf("Vetor aleatório\n");
	vetorAleatorio(vetor, tamVetor);
	start = clock();
	numComp = selectionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor inverso\n");
	vetorInverso(vetor, tamVetor);
	start = clock();
	numComp = selectionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor ordenado\n");
	vetorOrdenado(vetor, tamVetor);
	start = clock();
	numComp = selectionSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	
	printf("\nMerge Sort:\n");
	printf("Vetor aleatório\n");
	vetorAleatorio(vetor, tamVetor);
	start = clock();
	numComp = mergeSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor inverso\n");
	vetorInverso(vetor, tamVetor);
	start = clock();
	numComp = mergeSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor ordenado\n");
	vetorOrdenado(vetor, tamVetor);
	start = clock();
	numComp = mergeSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);

	printf("\nQuick Sort:\n");
	printf("Vetor aleatório\n");
	vetorAleatorio(vetor, tamVetor);
	start = clock();
	numComp = quickSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor inverso\n");
	vetorInverso(vetor, tamVetor);
	start = clock();
	numComp = quickSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor ordenado\n");
	vetorOrdenado(vetor, tamVetor);
	start = clock();
	numComp = quickSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);

	printf("\nHeap Sort:\n");
	printf("Vetor aleatório\n");
	vetorAleatorio(vetor, tamVetor);
	start = clock();
	numComp = heapSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor inverso\n");
	vetorInverso(vetor, tamVetor);
	start = clock();
	numComp = heapSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);
	printf("Vetor ordenado\n");
	vetorOrdenado(vetor, tamVetor);
	start = clock();
	numComp = heapSort(vetor, tamVetor);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\tcomparações: %d\n\ttempo: %f\n", numComp, total);

	free(vetor);
	return 0;
}
