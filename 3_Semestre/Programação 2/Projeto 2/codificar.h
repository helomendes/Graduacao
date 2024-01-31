#ifndef PRINCIPAIS_H
#define PRINCIPAIS_H

#include "structs.h"
#include "chave.h"

struct vetor *criarVetor();

int adicionarVetor(struct vetor *codes, int num);

void destruirVetor(struct vetor *codes);

int codificar(FILE *mensO, FILE *chave, FILE *mensC);

int codificarMensagem(char *lC, char *mO, char *mC, char *aC);

#endif
