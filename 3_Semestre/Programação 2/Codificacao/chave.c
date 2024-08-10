#include "chave.h"

char lerChar(FILE *arq) {
	char caractere;
	caractere = getc(arq);
	if (caractere >= 65 && caractere <= 90)
		caractere = caractere + 32;
	return caractere;
}

int adicionarLista(struct caractere *lista, char c, int n) {
	//confere se a lista está vazia
	if (lista->c == 0) {
		lista->c = c;
		lista->place->n = n;
		lista->lprox = NULL;
		lista->place->pprox = NULL;
		lista->ant = NULL;
		return 0;
	}
	//lista não vazia
	struct caractere *aux = lista;
	while (aux->ant != NULL)
		aux = aux->ant;
	//confere se c é igual ao primeiro item da lista
	if ((aux->c - c) == 0) {
		struct posicao *p = aux->place;
		while (p->pprox != NULL)
			p = p->pprox;
		p->pprox = malloc(sizeof(struct posicao));
		p->pprox->n = n;
		p->pprox->pprox = NULL;
		return 0;
	}
	//confere se c é menor que aux->c e este é o primeiro item
	//adiciona no começo
	if ((aux->c - c) > 0) {
		struct caractere *novo;
		novo = malloc(sizeof(struct caractere));
		novo->place = malloc(sizeof(struct posicao));
		novo->c = c;
		novo->place->n = n;
		novo->lprox = aux;
		novo->ant = aux->ant;
		aux->ant = novo;
		novo->place->pprox = NULL;
		return 0;
	}
	//confere se c é maior que aux->c
	if ((aux->c - c) < 0) {
		//enquanto aux->lprox->c for menor que c e é não nulo
		while (aux->lprox != NULL && (aux->lprox->c - c) < 0)
			aux = aux->lprox;
		//o proximo é nulo e aux->c é menor que c
		//adiciona no final
		if (aux->lprox == NULL && (aux->c - c) < 0) {
			aux->lprox = malloc(sizeof(struct caractere));
			aux->lprox->place = malloc(sizeof(struct posicao));
			aux->lprox->c = c;
			aux->lprox->ant = aux;
			aux->lprox->place->n = n;
			aux->lprox->lprox = NULL;
			aux->lprox->place->pprox = NULL;
			return 0;
		}
		//são iguais
		if ((aux->c - c) == 0) {
			struct posicao *p = aux->lprox->place;
			while (p->pprox != NULL)
				p = p->pprox;
			p->pprox = malloc(sizeof(struct posicao));
			p->pprox->n = n;
			p->pprox->pprox = NULL;
			return 0;
		}
		//o proximo não é nulo e é maior que c
		//ou seja, c está entre aux e aux->l
		//adiciona no meio
		if (aux->lprox != NULL && (aux->lprox->c - c) > 0) {
			struct caractere *novo;
			novo = malloc(sizeof(struct caractere));
			novo->place = malloc(sizeof(struct posicao));
			novo->c = c;
			novo->place->n = n;
			novo->ant = aux;
			novo->lprox = aux->lprox;
			aux->lprox->ant = novo;
			aux->lprox = novo;
			return 0;
		}
	}
	while (aux->lprox != NULL) {
		aux = aux->lprox;
		if ((aux->c - c) == 0) {
			struct posicao *p = aux->place;
			while (p->pprox != NULL)
				p = p->pprox;
			p->pprox = malloc(sizeof(struct posicao));
			p->pprox->n = n;
			p->pprox->pprox = NULL;
			return 0;
		}
	}
	aux->lprox = malloc(sizeof(struct caractere));
	aux->lprox->place = malloc(sizeof(struct posicao));
	aux->lprox->c = c;
	aux->lprox->place->n = n;
	aux->lprox->lprox = NULL;
	aux->lprox->place->pprox = NULL;
	return 0;
}

void escreverArquivo(FILE *arq, struct caractere *lista) {
	struct caractere *l;
	struct posicao *p;
	l = lista;
	while (l->ant != NULL)
		l = l->ant;
	while (l != NULL) {
		p = l->place;
		fprintf(arq, "%c:", l->c);
		while (p != NULL) {
			fprintf(arq, " %d", p->n);
			p = p->pprox;
		}
		fprintf(arq, "\n");
		l = l->lprox;
	}
}

void destruirLista(struct caractere *lista) {
	struct caractere *remover = lista;
	while (remover->ant != NULL)
		remover = remover->ant;
	struct caractere *auxr;
	struct posicao *p;
	struct posicao *auxp;
	while (remover != NULL) {
		p = remover->place;
		while (p != NULL) {
			auxp = p->pprox;
			free(p);
			p = auxp;
		}
	        auxr = remover->lprox;
		free(remover);
		remover = auxr;
	}
}

int arquivoDeChaves(FILE *livroCifra, FILE *arquivoChave) {
	struct caractere *lista;
	lista = malloc(sizeof(struct caractere));
	lista->place = malloc(sizeof(struct posicao));
	lista->c = 0;
	lista->place->n = '\0';
	lista->lprox = NULL;
	lista->place->pprox = NULL;

	char caractere = lerChar(livroCifra);
	char caractereAnt = 32;
	int contChar = 0;

	while(!feof(livroCifra)) {
		if (caractereAnt == 32 || caractereAnt == 10) {
			if (caractere >= 33 && caractere <= 126) {
				adicionarLista(lista, caractere, contChar);
				contChar++;
			}
		}
		caractereAnt = caractere;
		caractere = lerChar(livroCifra);
	}

	escreverArquivo(arquivoChave, lista);

	destruirLista(lista);

	return 0;
}
