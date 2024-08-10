#ifndef __STRUCTS__
#define __STRUCTS__

#include "utils.h"

// Struct para sistemas lineares A*x = b de tamanho n
struct SL {
    real_t **A;
    real_t *b;
    real_t *x;
    int_t n;
};

// Funções para sistemas lineares
struct SL *inicializar_SL();

struct SL *copiar_SL(struct SL *SL);

void restaurar_SL(struct SL *alterada, struct SL *original);

void free_SL(struct SL *SL);

// Struct para sistemas lineares tridiagonais (a, d, c)*x = b de tamanho n
struct tridiagonal {
    real_t *a; 
    real_t *b; 
    real_t *c; 
    real_t *d; 
    real_t *x; 
    int_t n;
};

// Funções para sistemas lineares tridiagonais
struct tridiagonal *inicializar_3diagonal(struct SL *SL);

struct tridiagonal *copiar_SL3d(struct tridiagonal *SL3d);

void restaurar_SL3d(struct tridiagonal *alterada, struct tridiagonal *original);

void free_SL3d(struct tridiagonal *SL3d);

#endif
