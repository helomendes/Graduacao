#include <stdio.h>
#include <math.h>
#include "EG.h"
#include "toolbox.h"

/* retrosub: funcao faz a retrosubstituição do sistema linear(SL - A, b, x, n)
 * já triangularizado
 * @SL - ponteiro para a struct que guarda o sistema linear já triangularizado
*/
void retrosub(struct SL *SL) {
	for (int i = SL->n-1; i >= 0; --i) {
		SL->x[i] = SL->b[i];
		for (int j = i+1; j < SL->n; ++j)
			SL->x[i] -= SL->A[i][j] * SL->x[j];
		SL->x[i] /= SL->A[i][i];
	}
}

/* trocar_linha: função troca linhas do sistema linear apartir de um indice e
 * um pivo.
 * @A - vetor de ponteiros que aponta para a matriz que guarda os coeficientes
 * do sistema
 * @b - ponteiro para o vetor que guarda os termos independentes do sistema
 * @i - inteiro de indice i que guarda a linha que será trocada
 * @pivo - inteiro de indice i + k que guarda a linha que será trocada
*/
void trocar_linha(real_t **A, real_t *b, int i, int pivo) {
	real_t *temp = A[i];
	A[i] = A[pivo];
	A[pivo] = temp;

	real_t tempB = b[i];
	b[i] = b[pivo];
	b[pivo] = tempB;
}

/* encontrar_max: função para encontrar o coeficiente maximo da coluna apartir
 * da diagonal do sistema.
 * @A - vetor de ponteiros que aponta para os coeficientes do sistema(matriz)
 * @n - variavel do tipo int_t que guarda o n do sistema
 * @i - inteiro que guarda o indice da linha e coluna de entrada
 *
 * return - retorna o indice da da linha, a qual o modulo do coeficiente é o
 * maior que os demais apartir da diagonal i.
*/
int encontrar_max(real_t **A, int_t n, int i) {
	int maxIndex = i;
	real_t max = A[i][i];
	for (int k = i + 1; k < n; k++) {
		if (A[k][i] > fabs(max)) {
			max = A[k][i];
			maxIndex = k;
		}
	}
	return maxIndex;
}

/* pivoteamento parcial: faz o pivoteamento parcial do sistema linear
 * (SL - A, b, x, n) de entrada.
 * @SL - ponteiro para a struct que guarda a estrutura do sistema linear de
 * entrada
*/
void pivoteamento_parcial(struct SL *SL) {
	for (int i = 0; i < SL->n; i++) {
		int pivo = encontrar_max(SL->A, SL->n, i);
		if (i != pivo) {
			trocar_linha(SL->A, SL->b, i, pivo);
		}
	}
}

/* eliminacao_gauss: função aplica o método de eliminação de gauss no sistema
 * linear de entrada(SL - A, x, b, n)
 * @SL - ponteiro para struct SL que guarda a estrutura do sistema linear
 *
 * return - retorn INDETERMINADO para divisao 0/0, IMPOSSIVEL para
 * (coeficien != 0 div 0) ou POSSIVEL para os demais casos.
*/
int eliminacao_gauss(struct SL *SL) {
	real_t tempo = timestamp();

	printf("EG clássico:\n");
	pivoteamento_parcial(SL);
	for (int i = 0; i < SL->n; i++) {
		for (int k = i+1; k < SL->n; k++) {

			if (SL->A[i][i] == 0) {
				if (SL->A[k][i] == 0) 
					return INDETERMINADO;

				return IMPOSSIVEL;
			}

			real_t m = SL->A[k][i] / SL->A[i][i];
			SL->A[k][i] = 0.0;
			for (int j = i+1; j < SL->n; j++) {
				SL->A[k][j] -= SL->A[i][j] * m;
			}
			SL->b[k] -= SL->b[i] * m;
		}
	}
	return POSSIVEL;
}

/* calcular_residuo: calcula o resíduo do sistema apartir de de uma matriz de
 * coeficientes e vetor de termos independentes originais e um vetor de
 * incognitas. (SL - A, b, x, n)
 * @copia - ponteiro para struct SL que guarda a matriz de coeficientes e vetor
 * de termos independentes original, sem operaçoes de eliminação de gauss
 * @SL - ponteiro para struct SL que sofreu alterações da eliminação de gauss e
 * calculou as incognitas
 *
 * return - retorna um ponteiro para o vetor de resíduos (real_t para
 * representar pontos flutuantes)
*/
real_t *calcular_residuo(struct SL *copia, struct SL *SL) {
	real_t *residuo = (real_t *)malloc(SL->n * sizeof(real_t));
	for (int i = 0; i < SL->n; i++) {
		residuo[i] = 0.0;
		for (int j = 0; j < SL->n; j++) {
			residuo[i] += (copia->A[i][j] * SL->x[j]);
		}
		residuo[i] -= copia->b[i];
	}
	return residuo;
}

/* retrosub_3diagonal: faz retrosubstituicao no sistema linear tridiagonal
 * (SL3d - a, d, c, b, x, n)
 * @SL3d - ponteiro para struct tridiagonal que guarda a estrutura do sistema
 * tridiagonal.
*/
void retrosub_3diagonal(struct tridiagonal *SL3d) {
	SL3d->x[SL3d->n-1] = SL3d->b[SL3d->n-1] / SL3d->d[SL3d->n-1];
	for (int i= SL3d->n-2; i >= 0; i--)
		SL3d->x[i] = (SL3d->b[i] - SL3d->c[i] * SL3d->x[i+1]) / SL3d->d[i];

}

/* eliminacao_gauss_3diagonal: função faz eliminação de gauss em um sistema
 * linear tridiagonal(SL3d - a, d, c, b, x, n)
 * @SL3d - ponteiro para struct tridiagonal que guarda a estrutura do sistema
 * linear tridiagonal.
 *
 * return - retorna INTEDERMINADO se houver divisao 0/0, IMPOSSIVEL SE
 * (coeficiente != 0 div 0) ou POSSIVEL para os dememais casos.
*/
int eliminacao_gauss_3diagonal(struct tridiagonal *SL3d) {
	printf("EG 3-diagonal:\n");
	for (int i=0; i < SL3d->n-1; i++) {

		if (SL3d->d[i] == 0) {
			if (SL3d->a[i] == 0) 
				return INDETERMINADO;

			return IMPOSSIVEL;
		}
		real_t m = SL3d->a[i] / SL3d->d[i];
		SL3d->a[i] = 0.0;
		SL3d->d[i+1] -= SL3d->c[i] * m;
		SL3d->b[i+1] -= SL3d->b[i] * m;
	}
	return POSSIVEL;
}

/* calcular_residuo_tridiagonal: função calcula o resíduo do sistema linear
 * tridiagonal(SL3d - a, d, c, b, x, n)
 * @SL3d - ponteiro para struct que guarda a estrutura do sistema tridiagonal e
 * que passou pela eliminação de gauss para o cálculo das incógnitas.
 * @copia - ponteiro para struct que guarda a estrutura do sistema tridiagonal
 * de entrada(original). Não passou pela eliminação de gauss.
 *
 * return - retona um ponteiro para o vetor de resíduos do sistema tridiagonal
 * (real_t para representar ponto flutuante)
*/
real_t *calcular_residuo_3diagonal(struct tridiagonal *copia, struct tridiagonal *SL3d) {
	real_t *residuo = (real_t *)malloc(SL3d->n * sizeof(real_t));
	residuo[0] = (copia->d[0] * SL3d->x[0]);
	residuo [0] += (copia->c[0] * SL3d->x[1]) - copia->b[0];
	for (int i = 1; i < SL3d->n-1; i++) {
		residuo[i] = (copia->d[i] * SL3d->x[i]) + (copia->a[i-1] * SL3d->x[i-1]);
		residuo[i] += (copia->c[i] * SL3d->x[i+1]);
		residuo[i] -= copia->b[i];
	}
	residuo[SL3d->n-1] = (copia->d[SL3d->n-1] * SL3d->x[SL3d->n-1]);
	residuo[SL3d->n-1] += (copia->a[SL3d->n-2] * SL3d->x[SL3d->n-2]);
	residuo[SL3d->n-1] -= copia->b[SL3d->n-1];
	return residuo;
}
