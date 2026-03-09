#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int menu();

struct compromisso{
	struct tm data;
	char *evento;
};

struct compromisso *criarCompromisso();

void adicionarCompromisso(struct compromisso *dia[], int i);

void inicializarAgenda(struct compromisso *dia[]);

void listarCompromissos(struct compromisso *dia[], int i);

void destruirAgenda(int i, struct compromisso *dia[]);
