#ifndef __allocM__
#define __allocM__

#include "structs.h"

// Macros de retorno para funções de resolução dos sistemas lineares
#define IMPOSSIVEL -1
#define INDETERMINADO 0
#define POSSIVEL 1

// Macros para o método Gauss-Seidel
#define LIM 50
#define TOL 0.0001

// Funções de execução
void executar_SL(struct SL *SL, struct SL *copia_SL, string_t nome, int (*metodo) (struct SL *SL));
void executar_SL3d(struct tridiagonal *SL3d, struct tridiagonal *copia_SL3d, string_t nome, int (*metodo) (struct tridiagonal *SL3d));

// Funções para alocação de memória
real_t **alocar_matriz(int_t n);
real_t *alocar_vetor(int_t n);

// Funções para desalocação de memória
void free_matriz(real_t **A, int_t n);
void free_vetor(real_t *x, int_t n);

// Função para ler o sistema linear
void ler_matriz(struct SL *SL);

// Funções para imprimir na saída padrão
void print_residuo(real_t *residuo, int_t n);
void print_incognita(real_t *x, int_t n);
void print_tempo(rtime_t tempo);

#endif
