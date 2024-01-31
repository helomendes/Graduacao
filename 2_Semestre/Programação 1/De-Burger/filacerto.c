#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filacerto.h"
#include "structs.h"

int getPedido (struct fila *ordem_pedidos, int *num_cliente){
    struct clientes *novo = malloc(sizeof(struct clientes));
	*num_cliente = *num_cliente + 1;
	novo->count = *num_cliente;
	novo->qual = rand() %6+1;
	novo->prox = NULL;
	novo->anterior = NULL;

	if (ordem_pedidos->inicio == NULL){                       //para adicionar primeiro elemento da fila;
		ordem_pedidos->inicio = novo;
	    ordem_pedidos->fim = ordem_pedidos->inicio;	
        ordem_pedidos->inicio->prox = NULL;
	    return (ordem_pedidos->inicio->qual);
	}
	else if (ordem_pedidos->fim == ordem_pedidos->inicio) {       // para adicionar segundo membro da fila
        novo->anterior = ordem_pedidos->fim->anterior;
		novo->prox = ordem_pedidos->fim;
	    ordem_pedidos->fim->anterior = novo;
		ordem_pedidos->fim = novo;
        ordem_pedidos->inicio->anterior = ordem_pedidos->fim;
        return (ordem_pedidos->fim->qual);
    }
    else {                                                       //adicionar demais nós
		novo->anterior = ordem_pedidos->fim->anterior;
		novo->prox = ordem_pedidos->fim;
		ordem_pedidos->fim->anterior = novo;
		ordem_pedidos->fim = novo;
        return (ordem_pedidos->fim->qual);
    }
    free(novo);
}


void pop_fila (struct fila *pedido_feito){
    struct clientes *Aux;
    Aux = pedido_feito->inicio;
    if (Aux==NULL){
        printf ("\n yo não tem nada ai");
    }
    else{
        pedido_feito->inicio = Aux->anterior;
        pedido_feito->inicio->prox = NULL;
	Aux->anterior = NULL;
        Aux->prox = NULL;
	free(Aux);
    }
}

void imprimirTodosPedidos(struct fila *pedido_impresso){
    struct clientes *aux;
    aux = pedido_impresso->inicio;
    while(aux){
    int c = aux->count;
    printf ("cliente %d: ", aux->count);
    if(aux->qual == 1)
	    printf("X-BURGER | ");
    else if(aux->qual == 2)
	    printf("X-SALADA | ");
    else if(aux->qual == 3)
	    printf("COMBO 1 | ");
    else if(aux->qual == 4)
	    printf("COMBO 2 | ");
    else if(aux->qual == 5)
	    printf("VEGETARIANO | ");
    else if(aux->qual == 6)
	    printf("VEGANO | ");
    if (aux->count % 5 == 0){
        printf ("\n\n\t\t\t\t");
    }
        aux = aux->anterior;
    }
}

void checarpedido(int *pedido, struct fila *meuspedidos){
    int a;
    a = meuspedidos->inicio->qual;
    *pedido=a;
}
