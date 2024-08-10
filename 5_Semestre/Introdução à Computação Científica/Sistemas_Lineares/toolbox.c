#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <likwid.h>
#include "toolbox.h"
#include "EG.h"
#include "GS.h"

/* executar_SL: resolve o sistema linear através da função parâmetro com
*  cronometragem de tempo e análise de operações de ponto flutuante
*  @SL - variável do tipo struct SL que representa o sistema linear a ser
*  resolvido
*  @copia_SL - variável do tipo struct SL com uma cópia do sistema linear
*  original
*  @nome - variável do tipo string_t com o rótulo do marcador de região
*  do LIKWID
*  @metodo - função a ser aplicada no sistema linear
*/
void executar_SL(struct SL *SL, struct SL *copia_SL, string_t nome, int (*metodo) (struct SL *SL)) {
	int estado;
	rtime_t tempo;

	LIKWID_MARKER_START(nome);
	tempo = timestamp();
	estado = metodo(SL);
	if (nome[0] == 'E')
		retrosub(SL);
	tempo = timestamp() - tempo;
	LIKWID_MARKER_STOP(nome);

	print_tempo(tempo);
	if (estado == POSSIVEL) {
		print_incognita(SL->x, SL->n);
		print_residuo(calcular_residuo(copia_SL, SL), SL->n);
	} else if (estado == INDETERMINADO) {
		printf("indeterminado\n");
	} else {
		printf("impossivel\n");
	}
	restaurar_SL(SL, copia_SL);
	printf("\n");
}

/* executar_SL3d: resolve o sistema linear tridiagonal com o método parâmetro
*  com cronometragem de tempo e análise de operações com ponto flutuante
*  @SL - variável do tipo struct tridiagonal que representa o sistema linear
*  tridiagonal a ser resolvido
*  @copia_SL - variável do tipo struct tridiagonal com uma cópia do sistema
*  linear original
*  @nome - variável do tipo string_t com o rótulo do marcador de região
*  do LIKWID
*  @metodo - função a ser aplicada no sistema linear tridiagonal
*/
void executar_SL3d(struct tridiagonal *SL3d, struct tridiagonal *copia_SL3d, string_t nome, int (*metodo) (struct tridiagonal *SL3d)) {
	int estado;
	real_t tempo;

	LIKWID_MARKER_START(nome);
	tempo = timestamp();
	estado = metodo(SL3d);
	if (nome[0] == 'E')
		retrosub_3diagonal(SL3d);
	tempo = timestamp() - tempo;
	LIKWID_MARKER_STOP(nome);

	print_tempo(tempo);
	if (estado == POSSIVEL) {
		print_incognita(SL3d->x, SL3d->n);
		print_residuo(calcular_residuo_3diagonal(copia_SL3d, SL3d), SL3d->n);
	} else if (estado == INDETERMINADO) {
		printf("indeterminado\n");
	} else {
		printf("impossivel\n");
	}
	restaurar_SL3d(SL3d, copia_SL3d);
	printf("\n");
}

/* alocar_matriz: aloca matriz do sistema linear dinamicamente
 * @n - variavel do tipo int_t que guarda o n do sistema linear
 *
 * return - retorna um ponteiro para matriz de pontos flutuantes(real_t)
*/
real_t **alocar_matriz(int_t n) { 
	real_t **A = (real_t **)malloc(n * sizeof(real_t *));
	assert(A != NULL);
	for (int i = 0; i < n; i++) {
		A[i] = (real_t *)calloc(n, sizeof(real_t));
		assert(A[i] != NULL);
	}
	return A;
}

/* free_matriz: funcao da free na matriz alocada
 * @A - vetor de ponteiros que aponta para cada coluna da matriz
 * @n - variavel do tipo int_t que guarda o n do sistema linear
*/
void free_matriz(real_t **A, int_t n) {
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);
}

/* aloca_vetor: aloca vetor dinamicamente
 * @n - variavel do tipo int_t que guarda o n do sistema linear
 *
 * return - um ponteiro para um vetor de pontos flutuantes(real_t)
*/
real_t *alocar_vetor(int_t n) {
	real_t *v = (real_t *)calloc(n, sizeof(real_t));
	assert(v != NULL);
	return v;
}

/* free_vetor: da free nos vetores alocados
 * @x - ponteiro para um vetor
 * @n - variavel do tipo int_t que guarda o n do sistema linear

*/
void free_vetor(real_t *x, int_t n) {
	free(x);
}

/* ler_matriz: funcao le a matriz de entrada
 * @SL - ponteiro para struct SL, a qual guarda um sistema linear aumentado,
* vetor de incognitas e um inteiro n
*/
void ler_matriz(struct SL *SL) {
	double k = 0;
	for (int i = 0; i < SL->n; i++) {
		for (int j = 0; j < SL->n; j++) {
			scanf("%lf", &k);
			SL->A[i][j] = k;
		}
		scanf("%lf", &k);
		SL->b[i] = k;
	}
}

/* print_residuo: printa o resíduo do sistema linear
 * @residuo - ponteiro para o vetor que guarda o residuo do sistema
 * @n - variavel do tipo int_t que guarda o n do sistema linear
*/
void print_residuo(double *residuo, int_t n) {
	for (int i = 0; i < n; i++) {
		printf("%.12lf ", residuo[i]);
	}
	printf("\n\n");
	free(residuo);
}

/* print_incognita: funcao printa o vetor de incognitas(solucao)
 * @x - ponteiro para o vetor x de incognitas
 * @n - variavel do tipo int_t que guarda o n do sistema linear
*/
void print_incognita(double *x, int_t n) {
	for (int i = 0; i < n; i ++) {
		printf ("%.12lf ", x[i]);
	}
	printf("\n");
}

/* print_tempo: funcao para printar o tempo
 * @tempo - variável do tipo rtime_t que guarda o tempo de execução do código
*/
void print_tempo(rtime_t tempo) {
	printf("%.8lf ms\n", tempo);
}
