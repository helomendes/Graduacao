#include <stdio.h>
#include <stdlib.h>
#include "pilhalib.h"

struct nop{
	int dado;
	struct nop *prox;
};//estrutura do no (cada uma das caixas)

struct pilha{
	struct nop *topo;
};//a pilha deve sempre ter um topo

void push(struct pilha **empilha, int quant){
	struct nop *p;//cria um no chamado p
	p = malloc(sizeof(struct nop));//alocação dinamica
	printf("Insira o dado: ");
	scanf("%d", &p->dado);
	if(quant)
		p->prox = (*empilha)->topo;
	else
		p->prox = NULL;
	(*empilha)->topo = p;//o topo da 'empilhação' recebe o dado p
	free(p);
}

void pop(struct pilha **empilha){
	(*empilha)->topo = (*empilha)->topo->prox;
}
