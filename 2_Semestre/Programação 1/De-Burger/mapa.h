#ifndef MAPA_H
#define MAPA_H

#include "structs.h"

#define LIN 10
#define COL 27

void criarMapa(char mapa[LIN][COL]);

void receitas();

int headerSleep();

void inicio();

int header();

void imprimirMapa(char mapa[LIN][COL], int chapeiro[], int pontos, double tempo, struct fila *ordem_pedido, struct pilha *refeicao);

void moverChapeiro(int chapeiro[], char mapa[LIN][COL], int pontos, double tempo, struct fila *ordem_pedido, struct pilha *refeicao);

int interacao(int chapeir[], char mapa[LIN][COL]);

void fim(int pontos);

void darFree(struct fila *ordem_pedido, struct pilha *refeicao);

#endif
