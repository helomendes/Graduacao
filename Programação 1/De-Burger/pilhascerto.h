#ifndef PILHASCERTO_H
#define PILHASCERTO_H
#include "structs.h"


void push (char ing,struct pilha *meal);

void checkXburg (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado);

void checkXsal (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado);

void checkCombo1 (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado);

void checkCombo2 (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado);

void checkVegetariano (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado);

void checkVegano (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado);

void verificaentrega (int pedido, struct pilha *mmeal,struct fila *fila_pedidos, int *ptr_ponto, int *ptr_lixo);

void poppilha(struct pilha *refeicao);

void definirRefeicao (int interacacao, struct pilha *mmeal, int pedido, struct fila *fila_pedidos,int *ptr_ponto, int *ptr_errado, int *ptr_lixo);

void imprimirPilha(struct pilha *refeicao);

void deletarSanduiche (struct pilha *meall);

#endif //PILHASCERTO_H
