#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct posicao {
	int n;
	struct posicao *pprox;
};

struct caractere {
	char c;
	struct caractere *lprox;
	struct caractere *ant;
	struct posicao *place;
};

struct vetor {
	long int n;
	struct vetor *prox;
	struct vetor *ant;
};

#endif
