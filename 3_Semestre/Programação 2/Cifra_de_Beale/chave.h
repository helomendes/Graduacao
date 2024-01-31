#ifndef CHAVE_H
#define CHAVE_H

#include "structs.h"

char lerChar(FILE *arq);

int adicionarLista(struct caractere *lista, char c, int n);

void escreverArquivo(FILE *arq, struct caractere *lista);

void destruirLista(struct caractere *lista);

int arquivoDeChaves(FILE *livroCifra, FILE *arquivoChave);

#endif
