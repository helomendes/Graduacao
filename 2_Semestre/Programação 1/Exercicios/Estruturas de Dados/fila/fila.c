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

void destruirFila(struct fila **f){
	while((*f)->head != NULL){
		free((*f)->head);
		(*f)->head = (*f)->head->prox;
	}
}

int menu(){
	int opcao;
	printf("Insira a opção desejada:\n");
	printf("\t1 Enfileirar\n");
	printf("\t2 Desenfileirar\n");
	printf("\t3 Imprimir fila\n");
	printf("\t4 Sair\n");
	scanf("%d", &opcao);
	printf("\n");
	return opcao;
}

int main(){
	struct fila *f;
	f = malloc(sizeof(struct fila));
	inicializarFila(&f);
	int op = menu();
	while(op <= 4 && op >= 1){
		if(op == 1)
			enqueue(&f);
		else if(op == 2)
			dequeue(&f);
		else if(op == 3)
			imprimirFila(&f);
		else{
			destruirFila(&f);
			free(f);
			return 0;
		}
		op = menu();
	}
	return 0;
}
