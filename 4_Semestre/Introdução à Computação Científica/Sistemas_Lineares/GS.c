#include <stdio.h>
#include "GS.h"
#include "toolbox.h"

/* sum: Soma da linha i da matriz A multiplicada pelo vetor de incognidas X
 * excluindo-se o valor pertencente à diagonal principal da matriz
 * @i - inteiro indice da linha a ser somada
 * @n - varivavel do tipo int_t que guarda o n do sistema linear
 * @A - vetor de ponteiros que aponta para a matriz de coeficientes
 * @X - ponteiro para o vetor de incognitas do sistema linear
 * 
 * return - retorna a soma dos coeficientes da linha com suas respectivas
 * incognitas em ponto flutuante
*/
real_t sum(int i, int_t n, real_t **A, real_t *X) {
	real_t sum = 0;
	for (int j = 0; j < n; j++) {
		if (j == i)
			continue;
		sum += A[i][j] * X[j];
	}
	return sum;
}


/* gauss_seidel: Implementação do método Gauss-Seidel para a resolução de
 * sistemas lineares A*x=B com tolerância de erro de 0.0001 e limite de 50
 * iterações (definidos em toolbox.h)
 * Imprime na saída padrão o nome do método e o número de iterações realizadas
 * @SL - ponteiro para struct que guarda o sistema linear de entrada
 *
 * return - retorna INDETERMINADO se a tolerância de erro não for atingida no
 * limite de iterações ou divisão 0/0, IMPOSSIVEL para (coeficiente != 0 div 0)
 * ou POSSIVEL para os demais casos.
 * Existem casos de retorno INDETERMINADO para sistemas possíveis, porém que
 * não tem a diagonal dominate.
*/
int gauss_seidel(struct SL *SL) {
	real_t temp;
	real_t erro = TOL + 1;
	real_t difference;
	int k = 0;

	printf("GS clássico");
	while (erro > TOL && k < LIM) {
		erro = -1;
		for (int i = 0; i < SL->n; i++) {
			temp = SL->b[i] - sum(i, SL->n, SL->A, SL->x);
                        if (SL->A[i][i] == 0) {
                                printf(" [ %d iterações ]:\n", k);
                                if (temp == 0) 
                                        return INDETERMINADO;
                                return IMPOSSIVEL;
                        }
			temp = temp	/ SL->A[i][i];
			difference = ABS(temp - SL->x[i]);
			if (difference > erro)
				erro = difference;
			SL->x[i] = temp;
		}
		k++;
	}
	printf(" [ %d iterações ]:\n", k);
	if (k >= LIM)
		return INDETERMINADO;
	return POSSIVEL;
}

/* gauus_seidel_3diagonal: implementação do método Gauss-Seidel específico para
 * a resolução de sistemas lineares tridiagonais (a, d, c)*x = b com tolerância
 * de 0.0001 e limite de 50 iterações (definidos em toolbox.h)
 * Imprime na saída padrão o nome do método e o número de iterações realizadas
 * @SL3d - ponteiro para struct tridiagonal que guarda o sistema linear tridiagonal
 *
 * return - retorna INDETERMINADO se a tolerância de erro não for atingida no
 * limite de iterações ou divisão 0/0, IMPOSSIVEL para (coeficiente != 0 div 0)
 * e POSSIVEL para os demais casos.
 * Existem casos de retorno INDETERMINADO para sistemas possíveis, porém não tem
 * diagonal dominate.
*/
int gauss_seidel_3diagonal(struct tridiagonal *SL3d) {
	int k = 0;
	real_t temp;
	real_t difference;
	real_t erro = 1 + TOL;

	printf("GS 3-diagonal");
	while (erro > TOL && k < LIM) {
		erro = 0.0;
		for (int i = 0; i < SL3d->n; i++) {
			temp = SL3d->x[i];
			SL3d->x[i] = SL3d->b[i];
			if (i == 0)
				SL3d->x[i] = SL3d->x[i] - SL3d->c[i] * SL3d->x[i+1];
			else if (i == SL3d->n-1)
				SL3d->x[i] = SL3d->x[i] - SL3d->a[i-1] * SL3d->x[i-1];
			else {
				SL3d->x[i] = SL3d->x[i] - SL3d->a[i-1] * SL3d->x[i-1];
		       		SL3d->x[i] -= SL3d->c[i] * SL3d->x[i+1];
			}
                        if (SL3d->d[i] == 0) {
                                printf(" [ %d iterações ]:\n", k);
                                if (SL3d->x[i] == 0) 
                                        return INDETERMINADO;
                                return IMPOSSIVEL;
                        }

			SL3d->x[i] = SL3d->x[i] / SL3d->d[i];
			difference = ABS(SL3d->x[i] - temp);
			if (difference > erro)
				erro = difference;
		}
		k++;
	}
	printf(" [ %d iterações ]:\n", k);
	if (k >= LIM)
		return INDETERMINADO;
	return POSSIVEL;
}
