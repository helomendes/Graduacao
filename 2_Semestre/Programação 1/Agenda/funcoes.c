#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

#define TAM 24
#define ANO 365

int menu(){
	int aux;
	printf("Digite a opção desejada:\n0\tAdicionar um compromisso\n1\tCriar uma agenda para o dia\n2\tVisualizar a agenda\n3\tSair\n");
	scanf("%d", &aux);
	return aux;
}

struct compromisso *criarCompromisso(){
	size_t tam = 100;

	struct compromisso *c;
	c = malloc(sizeof(struct compromisso));
	c->evento = malloc(tam*sizeof(char));

	printf("Digite a data do seu compromisso (DD MM): ");
	scanf("%d %d", &c->data.tm_mday, &c->data.tm_mon);

	printf("Digite o horário do seu compromisso (HH): ");
	scanf("%d", &c->data.tm_hour);

	printf("Qual é o compromisso? ");
	getchar();
	fgets(c->evento, tam*sizeof(char), stdin);
	c->evento[strcspn(c->evento, "\n")] = '\0';

	printf("\nSeu compromisso '%s' será marcado na data %d/%d às %d:00 horas...\n", c->evento, c->data.tm_mday, c->data.tm_mon, c->data.tm_hour);

	return c;
}

void adicionarCompromisso(struct compromisso *dia[], int i){
	struct compromisso *c;
	c = criarCompromisso();

	for(int j=0; j<=i; j++){
		if(dia[j]->data.tm_mday == c->data.tm_mday && dia[j]->data.tm_mon+1 == c->data.tm_mon+1){
			printf("\nok 1\n");
			if(dia[j]->data.tm_hour == c->data.tm_hour){
				printf("\nHora %d já ocupada\n", c->data.tm_hour);
				free(c->evento);
				free(c);
			}
			else{
				printf("\nHora livre, preenchendo...\n");
				dia[i+1] = c;
				printf("\nEvento '%s' marcado!\n", dia[i+1]->evento);
				free(c->evento);
				free(c);
			}
			break;
		}
		else if (j == i){
			printf("\nok 2\n");
			printf("\nHora livre, preenchendo...\n");
			dia[i+1] = c;
			printf("\nEvento '%s' marcado!\n", dia[i+1]->evento);
			free(c->evento);
			free(c);
		}
	}
}

void inicializarAgenda(struct compromisso *dia[]){
	for(int i = 0;  i<ANO; i++)
		dia[i] = NULL;
}

void listarCompromissos(struct compromisso *dia[], int i){
	for(int p = 0; p<=i; p++){
		printf("%s - %d/%d às %d:00h\n", dia[p]->evento, dia[p]->data.tm_mday, dia[p]->data.tm_mon, dia[p]->data.tm_hour);
	}
}

void destruirAgenda(int i, struct compromisso *dia[]){
   	for(int j = 0; j<=i; j++){
   		free(dia[j]);
		free(dia[j]->evento);
	}
}

