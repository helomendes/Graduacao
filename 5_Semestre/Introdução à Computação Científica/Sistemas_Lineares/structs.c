#include <stdio.h>
#include <assert.h>
#include "toolbox.h"

/* inicializar_SL: inicializa o sitema linear alocando dinamicamente
*/
struct SL *inicializar_SL() {
	struct SL *SL = (struct SL *)malloc(sizeof(struct SL));
	assert(SL != NULL);
	scanf("%lu", &SL->n);
	SL->A = alocar_matriz(SL->n);
	SL->b = alocar_vetor(SL->n);
	SL->x = alocar_vetor(SL->n);
	ler_matriz(SL);
	return SL;
}

/* copiar_SL: faz a cópia do sistema linear original da entrada
 * @SL - ponteiro para a struct que guarda o sistema linear que ainda não foi alterada
*/
struct SL *copiar_SL(struct SL *SL) {
	struct SL *copia = (struct SL*)malloc(sizeof(struct SL));
	assert(SL != NULL);
	copia->n = SL->n;
	copia->A = alocar_matriz(copia->n);
	copia->b = (real_t *)calloc(copia->n, sizeof(real_t));
	assert(copia->b != NULL);
	copia->x = (real_t *)calloc(copia->n, sizeof(real_t));
	assert(copia->x != NULL);
	for (int i = 0; i < SL->n; i++) {
		for (int j = 0; j < SL->n; j++)
			copia->A[i][j] = SL->A[i][j];
		copia->b[i] = SL->b[i];
	}
	return copia;
}

/* restaurar_SL: restaura o sistema alterado apartir de uma cópia
 * @alterada - struct que guarda o sistema linear que foi modificada pela eliminacao de gauss
 * @original - struct original que é copia do sitema linear de entrada
*/
void restaurar_SL(struct SL *alterada, struct SL *original) {
	for (int i = 0; i < alterada->n; i++) {
		alterada->x[i] = 0.0;
		alterada->b[i] = original->b[i];
		for (int j = 0; j < alterada->n; j++)
			alterada->A[i][j] = original->A[i][j];
	}
}

/* free_SL: da free em toda estrutura SL
 * @SL - ponteiro para struct SL que guarda o sistema linear de entrada e incognitas
*/
void free_SL(struct SL *SL) {
	free_matriz(SL->A, SL->n);
	free_vetor(SL->b, SL->n);
	free_vetor(SL->x, SL->n);
	free(SL);
}

/* inicializar_3diagonal: inicializa sistema tridiagonal apartir de um sistema linear ja alocado
 * @SL - ponteiro para struct que guarda o sistema linear
*/
struct tridiagonal *inicializar_3diagonal(struct SL *SL) {
	struct tridiagonal *SL3d = (struct tridiagonal *)malloc(sizeof(struct tridiagonal));
	SL3d->n = SL->n;
	SL3d->a = alocar_vetor(SL3d->n);
	SL3d->b = alocar_vetor(SL3d->n);
	SL3d->c = alocar_vetor(SL3d->n);
	SL3d->d = alocar_vetor(SL3d->n);
	SL3d->x = alocar_vetor(SL3d->n);
	for (int i = 0; i < SL->n; i++) {
		if (i == SL->n-1) {
			SL3d->d[i] = SL->A[i][i];
			SL3d->b[i] = SL->b[i];
		} else {
			SL3d->a[i] = SL->A[i+1][i];
			SL3d->b[i] = SL->b[i];
			SL3d->c[i] = SL->A[i][i+1];
			SL3d->d[i] = SL->A[i][i];
			SL3d->x[i] = SL->x[i];
		}
		
	}
	return SL3d;
}

/* copiar_SL3d: faz a cópia do sistema linear de entrada
 * @SL3d - ponteriro para struct que guarda o sistema linear tridiagonal
*/
struct tridiagonal *copiar_SL3d(struct tridiagonal *SL3d) {
	struct tridiagonal *copia = (struct tridiagonal *)malloc(sizeof(struct tridiagonal));
	copia->n = SL3d->n;
	copia->a = alocar_vetor(SL3d->n);
	copia->b = alocar_vetor(SL3d->n);
	copia->c = alocar_vetor(SL3d->n);
	copia->d = alocar_vetor(SL3d->n);
	copia->x = alocar_vetor(SL3d->n);
	for (int i = 0; i < SL3d->n; i++) {
		copia->a[i] = SL3d->a[i];
		copia->b[i] = SL3d->b[i];
		copia->c[i] = SL3d->c[i];
		copia->d[i] = SL3d->d[i];
	}
	return copia;
}

/* restaurar_SL3d: restaura o sistema apartir de um cópia
 * @alterada - ponteiro para a struct tridiagonal alterada pela eliminacao de gauss
 * @original - ponteiro para struct tridiagonal que é a copia original do sistema linear de entrada
*/
void restaurar_SL3d(struct tridiagonal *alterada, struct tridiagonal *original)   {
	for (int i = 0; i < alterada->n; i++) {
		alterada->x[i] = 0.0;
		if (i < alterada->n - 1) {
			alterada->a[i] = original->a[i];
			alterada->c[i] = original->c[i];
		}
		alterada->d[i] = original->d[i];
		alterada->b[i] = original->b[i];
	}
}

/* free_SL3d: da free em todos estruturas dentro do sistema linear tridiagonal
 * @SL3d - ponteiro para a struct que guarda o sistema linear tridiagonal
*/
void free_SL3d(struct tridiagonal *SL3d) {
	free_vetor(SL3d->a, SL3d->n);
	free_vetor(SL3d->b, SL3d->n);
	free_vetor(SL3d->c, SL3d->n);
	free_vetor(SL3d->d, SL3d->n);
	free_vetor(SL3d->x, SL3d->n);
	free(SL3d);
}
