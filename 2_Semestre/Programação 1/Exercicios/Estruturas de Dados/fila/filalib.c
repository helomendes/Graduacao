#include <stdio.h>
#include <stdlib.h>
#include "filalib.h"

struct unit{
	int dado;
	struct unit *prox;
};

struct fila{
	struct unit *head;
	struct unit *tail;
};

void inicializarFila(struct fila **f){
	(*f)->head = NULL;
	(*f)->tail = NULL;
}

void criarElemento(struct unit **novo){
	printf("Insira o elemento: ");
	scanf("%d", &(*novo)->dado);
	printf("\n");
	(*novo)->prox = NULL;
	free(novo);
}

void enqueue(struct fila **f){
	struct unit *novo;
	novo = malloc(sizeof(struct unit));
	criarElemento(&novo);

	if ((*f)->head == NULL){
		(*f)->head = novo;
		(*f)->tail = novo;
	}
	else{
		(*f)->tail->prox = novo;
		(*f)->tail = novo;
	}
}

void dequeue(struct fila **f){
	if ((*f)->head != NULL){
		free((*f)->head);
		(*f)->head = (*f)->head->prox;
	}
}

void imprimirFila(struct fila **f){
	printf("Imprimindo fila...\n");
	if((*f)->head == NULL)
		printf("\nFila vazia\n\n");
	else if((*f)->head != NULL){
		struct unit *aux;
		aux = malloc(sizeof(struct unit));
		aux = (*f)->head;
		while(aux != NULL){
			printf("%d\n", aux->dado);
			aux = aux->prox;
		}
		printf("\n");
		free(aux);
	}
}
