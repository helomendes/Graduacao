#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> // Para uso de função 'memset()'   
#include <immintrin.h>

#include "matriz_otimizada.h"

/**
 * Função que gera valores para para ser usado em uma matriz
 * @param i,j coordenadas do elemento a ser calculado (0<=i,j<n)
 *  @return valor gerado para a posição i,j
 */
static inline real_t generateRandomA( unsigned int i, unsigned int j)
{
        static real_t invRandMax = 1.0 / (real_t)RAND_MAX;
        return ( (i==j) ? (real_t)(BASE<<1) : 1.0 )  * (real_t)random() * invRandMax;
}

/**
 * Função que gera valores aleatórios para ser usado em um vetor
 * @return valor gerado
 *
 */
static inline real_t generateRandomB( )
{
        static real_t invRandMax = 1.0 / (real_t)RAND_MAX;
        return (real_t)(BASE<<2) * (real_t)random() * invRandMax;
}



/* ----------- FUNÇÕES ---------------- */

/**
 *  Funcao geraMatRow: gera matriz como vetor único, 'row-oriented', usando Padding
 * 
 *  @param m     número de linhas da matriz
 *  @param n     número de colunas da matriz
 *  @param zerar se 0, matriz  tem valores aleatórios, caso contrário,
 *               matriz tem valores todos nulos
 *  @return  ponteiro para a matriz gerada
 *
 */

MatRow geraMatRow_otimizada(int m, int n, int zerar)
{
        MatRow matriz = (real_t *) malloc(m*n*sizeof(real_t)+64);

        if (matriz) {
                if (zerar)
                        memset(matriz,0,m*n*sizeof(real_t));
                else
                        for (int i=0; i < m; ++i)
                                for (int j=0; j < n; ++j)
                                        matriz[i*n + j] = generateRandomA(i, j);
        }

        return (matriz);
}


/**
 *  Funcao geraVetor: gera vetor de tamanho 'n' usando Padding
 * 
 *  @param n  número de elementos do vetor
 *  @param zerar se 0, vetor  tem valores aleatórios, caso contrário,
 *               vetor tem valores todos nulos
 *  @return  ponteiro para vetor gerado
 *
 */

Vetor geraVetor_otimizada(int n, int zerar)
{
        Vetor vetor = (real_t *) malloc(n*sizeof(real_t));

        if (vetor) {
                if (zerar)
                        memset(vetor,0,n*sizeof(real_t));
                else
                        for (int i=0; i < n; ++i)
                                vetor[i] = generateRandomB();
        }

        return (vetor);
}

/**
 *  Funcao multMatVet:  Efetua multiplicacao entre matriz 'mxn' por vetor
 *                       de 'n' elementos usando Unroll & Jam de tamanho 8
 *  @param mat matriz 'mxn'
 *  @param m número de linhas da matriz
 *  @param n número de colunas da matriz
 *  @param res vetor que guarda o resultado. Deve estar previamente alocado e com
 *             seus elementos inicializados em 0.0 (zero)
 *  @return vetor de 'm' elementos
 *
 */

void multMatVet_otimizada(MatRow restrict mat, Vetor restrict v, int m, int n, Vetor restrict res)
{
        int bloco = m-m%UF;

        /* Efetua a multiplicação */
        for (int i=0; i < bloco; i+=UF) {
                for (int j=0; j < n; ++j) {
                        res[i] += mat[n*i + j] * v[j];
                        res[i+1] += mat[(n*(i+1)) + j] * v[j];
                        res[i+2] += mat[(n*(i+2)) + j] * v[j];
                        res[i+3] += mat[(n*(i+3)) + j] * v[j];
                        res[i+4] += mat[(n*(i+4)) + j] * v[j];
                        res[i+5] += mat[(n*(i+5)) + j] * v[j];
                        res[i+6] += mat[(n*(i+6)) + j] * v[j];
                        res[i+7] += mat[(n*(i+7)) + j] * v[j];
                }
        }

        for (int i=bloco; i < n; i++)
                for (int j=0; j < n; ++j) {
                        res[i] += mat[n*i+j] * v[j];
                }

}


/**
 *  Funcao multMatMat: Efetua multiplicacao de duas matrizes 'n x n' usando Blocking de tamanho 32 e Unroll & Jam de tamanho 8 
 *  @param A matriz 'n x n'
 *  @param B matriz 'n x n'
 *  @param n ordem da matriz quadrada
 *  @param C   matriz que guarda o resultado. Deve ser previamente gerada com 'geraMatPtr()'
 *             e com seus elementos inicializados em 0.0 (zero)
 *
 */

void multMatMat_otimizada(MatRow restrict A, MatRow restrict B, int n, MatRow restrict C)
{
    int b = BK;
    int istart, iend, jstart, jend, kstart, kend, in, kn = 0;

    for (int ii=0; ii<n/b; ++ii) {
            istart=ii*b; iend=istart+b;
            for (int jj=0; jj<n/b; ++jj) {
                    jstart=jj*b; jend=jstart+b;
                    for (int kk=0; kk<n/b; ++kk) {
                            kstart=kk*b; kend=kstart+b;
                            for (int i=istart; i < iend; ++i) {
                                    in = n*i;
                                    for (int j=jstart; j < jend; j+=UF)
                                            for (int k=kstart; k < kend; ++k) {
                                                    kn = k*n;
                                                    C[in+j] += A[in+k] * B[kn+j];
                                                    C[in+(j+1)] += A[in+k] * B[kn+(j+1)];
                                                    C[in+(j+2)] += A[in+k] * B[kn+(j+2)];
                                                    C[in+(j+3)] += A[in+k] * B[kn+(j+3)];
                                                    C[in+(j+4)] += A[in+k] * B[kn+(j+4)];
                                                    C[in+(j+5)] += A[in+k] * B[kn+(j+5)];
                                                    C[in+(j+6)] += A[in+k] * B[kn+(j+6)];
                                                    C[in+(j+7)] += A[in+k] * B[kn+(j+7)];

                                            }
                            }
                    }
            }
    }	

	for (int i = 0; i < iend; i++) {
		for (int j = 0; j < n; j++) {
			for (int k=jend; k < n; k++) {
				C[i*n+j] += A[i*n+k] * B[k*n+j];
			}
		}
	}

	for (int i=iend; i < n; ++i) {
		for (int j=0; j < n; j++)
			for (int k=0; k < n; ++k) {
				C[i*n+j] += A[i*n+k] * B[k*n+j];
			}
	}

}
