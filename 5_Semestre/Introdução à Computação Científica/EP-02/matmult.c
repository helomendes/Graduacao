#include <stdio.h>
#include <stdlib.h>    /* exit, malloc, calloc, etc. */
#include <string.h>
#include <getopt.h>    /* getopt */
#include <time.h>
#include <likwid.h>

#include "matriz.h"
#include "matriz_otimizada.h"
#include "utils.h"

/**
 * Exibe mensagem de erro indicando forma de uso do programa e termina
 * o programa.
 */

static void usage(char *progname)
{
  fprintf(stderr, "Forma de uso: %s [ <ordem> ] \n", progname);
  exit(1);
}



/**
 * Programa principal
 * Forma de uso: matmult [ -n <ordem> ]
 * -n <ordem>: ordem da matriz quadrada e dos vetores
 *
 */

int main (int argc, char *argv[]) 
{
  int n=DEF_SIZE;
  
  MatRow mRow_1, mRow_2, resMat;
  Vetor vet, res;
  
  /* =============== TRATAMENTO DE LINHA DE COMANDO =============== */

  if (argc < 2)
    usage(argv[0]);

  n = atoi(argv[1]);
  
  /* ================ FIM DO TRATAMENTO DE LINHA DE COMANDO ========= */
 
  srandom(20232);
      
// ******** VERSÃO OTIMIZADA ********

  res = geraVetor_otimizada(n, 1); // (real_t *) malloc (n*sizeof(real_t));
  resMat = geraMatRow_otimizada(n, n, 1);
    
  mRow_1 = geraMatRow_otimizada(n, n, 0);
  mRow_2 = geraMatRow_otimizada(n, n, 0);

  vet = geraVetor_otimizada(n, 0);

  if (!res || !resMat || !mRow_1 || !mRow_2 || !vet) {
    fprintf(stderr, "Falha em alocação de memória !!\n");
    liberaVetor ((void*) mRow_1);
    liberaVetor ((void*) mRow_2);
    liberaVetor ((void*) resMat);
    liberaVetor ((void*) vet);
    liberaVetor ((void*) res);
    exit(2);
  }
    
#ifdef _DEBUG_
    prnMat (mRow_1, n, n);
    prnMat (mRow_2, n, n);
    prnVetor (vet, n);
    printf ("=================================\n\n");
#endif /* _DEBUG_ */
 
  LIKWID_MARKER_INIT;

  rtime_t tmatvet;
  rtime_t tmatmat;

  LIKWID_MARKER_START("multMatVet_Otimizada");
  tmatvet = timestamp();
  multMatVet_otimizada(mRow_1, vet, n, n, res);
  tmatvet = timestamp() - tmatvet;
  LIKWID_MARKER_STOP("multMatVet_Otimizada");
    
  LIKWID_MARKER_START("multMatMat_Otimizada");
  tmatmat = timestamp();
  multMatMat_otimizada(mRow_1, mRow_2, n, resMat);
  tmatmat = timestamp() - tmatmat;
  LIKWID_MARKER_STOP("multMatMat_Otimizada");

#ifdef _DEBUG_
    prnVetor (res, n);
    prnMat (resMat, n, n);
#endif /* _DEBUG_ */


  printf("%d, %f, %f,", n, tmatvet, tmatmat);

  liberaVetor ((void*) mRow_1);
  liberaVetor ((void*) mRow_2);
  liberaVetor ((void*) resMat);
  liberaVetor ((void*) vet);
  liberaVetor ((void*) res);

// **************************

  res = geraVetor (n, 1); // (real_t *) malloc (n*sizeof(real_t));
  resMat = geraMatRow(n, n, 1);
    
  mRow_1 = geraMatRow (n, n, 0);
  mRow_2 = geraMatRow (n, n, 0);

  vet = geraVetor (n, 0);

  if (!res || !resMat || !mRow_1 || !mRow_2 || !vet) {
    fprintf(stderr, "Falha em alocação de memória !!\n");
    liberaVetor ((void*) mRow_1);
    liberaVetor ((void*) mRow_2);
    liberaVetor ((void*) resMat);
    liberaVetor ((void*) vet);
    liberaVetor ((void*) res);
    exit(2);
  }
    
#ifdef _DEBUG_
    prnMat (mRow_1, n, n);
    prnMat (mRow_2, n, n);
    prnVetor (vet, n);
    printf ("=================================\n\n");
#endif /* _DEBUG_ */
 
  LIKWID_MARKER_START("multMatVet");
  tmatvet = timestamp();
  multMatVet (mRow_1, vet, n, n, res);
  tmatvet = timestamp() - tmatvet;
  LIKWID_MARKER_STOP("multMatVet");
    
  LIKWID_MARKER_START("multMatMat");
  tmatmat = timestamp();
  multMatMat (mRow_1, mRow_2, n, resMat);
  tmatmat = timestamp() - tmatmat;
  LIKWID_MARKER_STOP("multMatMat");

  LIKWID_MARKER_CLOSE;  

#ifdef _DEBUG_
    prnVetor (res, n);
    prnMat (resMat, n, n);
#endif /* _DEBUG_ */

  printf("%f, %f\n", tmatvet, tmatmat);

  liberaVetor ((void*) mRow_1);
  liberaVetor ((void*) mRow_2);
  liberaVetor ((void*) resMat);
  liberaVetor ((void*) vet);
  liberaVetor ((void*) res);

  return 0;
}

