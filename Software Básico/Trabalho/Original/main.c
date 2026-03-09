#include <stdio.h>
#include <stdlib.h>

#include "memalloc.h" 							

extern void *original_brk;	/* Você precisa ter a variável global que armazena o valor de brk como um extern aqui.
							No código de teste estou chamandando de original_brk, mas se utilizarem outro nome,
							substituir as ocorrências por ele aqui. */

int main() { 

	printf("============================== ROTINAS DE TESTE ==============================\n");
	
	setup_brk();
	void *initial_brk = original_brk;
	void *pnt_1, *pnt_2, *pnt_3, *pnt_4, *pnt_5, *pnt_6, *pnt_7;

	pnt_1 = memory_alloc(100);
	printf("==>> ALOCANDO UM ESPAÇO DE 100 BYTES:\n");
	printf("\tLOCAL: %s\n", pnt_1-16 == initial_brk ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_1-16)) == 1 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_1-8)) == 100 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	pnt_2 = memory_alloc(130);
	printf("==>> ALOCANDO UM ESPAÇO DE 130 BYTES:\n");
	printf("\tLOCAL: %s\n", pnt_2-16 == initial_brk + 116 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_2-16)) == 1 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_2-8)) == 130 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tREL. PRIMEIRA ALOCAÇÃO: %s\n", (long long) (pnt_2-pnt_1) == 116 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	pnt_3 = memory_alloc(110);
	printf("==>> ALOCANDO UM ESPAÇO DE 110 BYTES:\n");
	printf("\tLOCAL: %s\n", pnt_3-16 == initial_brk + 262 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_3-16)) == 1 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_3-8)) == 110 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tREL. SEGUNDA ALOCAÇÃO: %s\n", (long long) (pnt_3-pnt_2) == 146 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	pnt_4 = memory_alloc(120);
	printf("==>> ALOCANDO UM ESPAÇO DE 120 BYTES:\n");
	printf("\tLOCAL: %s\n", pnt_4-16 == initial_brk + 388 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_4-16)) == 1 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_4-8)) == 120 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tREL. TERCEIRA ALOCAÇÃO: %s\n", (long long) (pnt_4-pnt_3) == 126 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	printf("==>> DESALOCANDO UM ESPAÇO DE 130 BYTES:\n");
	memory_free(pnt_2);
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_2-16)) == 0 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_2-8)) == 130 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	printf("==>> DESALOCANDO UM ESPAÇO DE 120 BYTES:\n");
	memory_free(pnt_4);
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_4-16)) == 0 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_4-8)) == 120 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	pnt_5 = memory_alloc(50);
	printf("==>> ALOCANDO UM ESPAÇO DE 50 BYTES:\n");
	printf("\tLOCAL: %s\n", pnt_5 == pnt_2 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_5-16)) == 1 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_5-8)) == 50 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	
	pnt_6 = memory_alloc(60);
	printf("==>> ALOCANDO UM ESPAÇO DE 60 BYTES:\n");
	printf("\tLOCAL: %s\n", pnt_6 == pnt_5+66 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_6-16)) == 1 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_6-8)) == 64 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	pnt_7 = memory_alloc(150);
	printf("==>> ALOCANDO UM ESPAÇO DE 150 BYTES:\n");
	printf("\tLOCAL: %s\n", pnt_7 == pnt_4+136 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_7-16)) == 1 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_7-8)) == 150 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	printf("==>> DESALOCANDO TUDO:\n");
	memory_free(pnt_1);
	memory_free(pnt_3);
	memory_free(pnt_5);
	memory_free(pnt_6);
	memory_free(pnt_7);
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_1-16)) == 0 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_1-8)) == 100 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_3-16)) == 0 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_3-8)) == 110 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_5-16)) == 0 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_5-8)) == 50 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_6-16)) == 0 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_6-8)) == 64 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tIND. DE USO: %s\n", *((long long*) (pnt_7-16)) == 0 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");
	printf("\tTAMANHO: %s\n", *((long long*) (pnt_7-8)) == 150 ? "\e[1;32mCORRETO!\e[00m" : "\e[1;31mINCORRETO!\e[00m");

	return 0;
}