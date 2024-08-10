#ifndef __GS__
#define __GS__

#include "structs.h"

// Funções para resolver sistemas lineares pelo método Gauss-Seidel
real_t sum(int i, int_t n, real_t **A, real_t *X);

int gauss_seidel(struct SL *SL);

// Função para resolver sistemas lineares tridiagonais pelo método Gauss-Seidel
int gauss_seidel_3diagonal(struct tridiagonal *SL3d);

#endif
