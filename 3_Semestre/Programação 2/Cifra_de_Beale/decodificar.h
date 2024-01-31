#ifndef LIB_H
#define LIB_H

#include "structs.h"
#include "chave.h"

char encontrarCode(FILE *arqC, int code);

int decodificarMensagem(char *mC, char *mD, char *lC, char *aC);

#endif
