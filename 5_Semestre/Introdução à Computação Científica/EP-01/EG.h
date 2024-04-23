#ifndef __EG__
#define __EG__

#include "structs.h"

// Funções para resolver sistemas lineares pela Eliminação de Gauss
void retrosub(struct SL *SL);

void trocar_linha(real_t **A, real_t *b, int i, int pivo);

int encontrar_max(real_t **A, int_t n, int i);

void pivoteamento_parcial(struct SL *SL);

int eliminacao_gauss(struct SL *SL);

real_t *calcular_residuo(struct SL *copia, struct SL *SL);

// Funções para resolver sistemas lineares tridiagonais pela Eliminação de Gauss
void retrosub_3diagonal(struct tridiagonal *SL3d);

int eliminacao_gauss_3diagonal(struct tridiagonal *SL3d);

real_t *calcular_residuo_3diagonal(struct tridiagonal *copia, struct tridiagonal *SL);

#endif

