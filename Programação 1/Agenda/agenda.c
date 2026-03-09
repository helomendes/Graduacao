#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

#define TAM 24
#define ANO 365

int main(){
	int i = 0;
	struct compromisso *dia[ANO];
	inicializarAgenda(dia);
	int opcao = 4;
	while(opcao != 3){
		opcao = menu();
		if(opcao == 0){
			adicionarCompromisso(dia, i);
			printf("\nEvento '%s' marcado!\n", dia[i]->evento);
			i++;
		}
		if(opcao == 1){
			char sai = 'a';
			while(sai != 'x'){
				adicionarCompromisso(dia, i);
				i++;
				printf("\nPressione 'x' para SAIR ou qualquer outra tecla para continuar... ");
				sai = getchar();
			}
		}
		if(opcao == 2){
			listarCompromissos(dia, i);
		}
	}
	if(opcao == 3){
		printf("Fechando a agenda...\n");
		destruirAgenda(i, dia);
	}
	return 0;
}
