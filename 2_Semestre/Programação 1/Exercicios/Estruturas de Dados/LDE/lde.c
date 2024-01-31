#include <stdio.h>
#include <stdlib.h>

int menu(){
	int op;
	printf("Insira a opção desejada:\n0\tteste vazia\n1\tInserir nó\n2\tRemover nó\n3\tMostrar a lista\n4\tSair\n");
	scanf("%d", &op);
	return op;
}

struct nold{
	int dado;
	struct nold *ant;
	struct nold *prox;
};

struct lde{
	struct nold *cabeca;
	struct nold *cauda;
};

void inicializaLista(struct lde **lista){
	(*lista) = malloc(sizeof(struct lde));
	(*lista)->cabeca = NULL;
	(*lista)->cauda = NULL;
}

void destroiLista(struct lde **lista){
	while((*lista)->cabeca != 0){
		free((*lista)->cabeca);
		(*lista)->cabeca = (*lista)->cabeca->prox;
	}
}

int estaVazia(struct lde **lista){
	if((*lista)->cabeca == NULL)
		return 1;
	return 0;
}

struct nold criaNo(struct nold **novo){
	int x;
	printf("Insira o novo dado: ");
	scanf("%d", &x);
	(*novo)->dado = x;
	(*novo)->prox = NULL;
	(*novo)->ant = NULL;
	return (**novo);
}

void inserePrimeiro(struct lde **lista, struct nold **novo){
	(*lista)->cabeca = (*novo);
	(*lista)->cauda = (*novo);
}

void insereCabeca(struct lde **lista, struct nold **novo){
	struct nold *aux;
	aux = (*lista)->cabeca;

	if((*novo)->dado > aux->dado){
		(*novo)->prox = aux->prox;
		aux->prox = (*novo);
		(*novo)->ant = aux;
	}

	else{
		(*novo)->prox = aux;
		(*novo)->ant = aux->ant;
		aux->ant = (*novo);
		(*lista)->cabeca = (*novo);
	}
}

void insereOrdenado(struct lde **lista, struct nold **novo){
	struct nold *aux;
	aux = (*lista)->cabeca;
	
	if(aux->dado > (*novo)->dado){
		(*novo)->ant = aux->ant;
		(*novo)->prox = aux;
		aux->ant = (*novo);
	}

	else{
		while(aux->dado <= (*novo)->dado)
			aux = aux->prox;

		if(aux->prox == NULL){
			(*novo)->prox = aux->prox;
			aux->prox = (*novo);
			(*novo)->ant = aux;
		}

		else{
			aux->prox->ant = (*novo);
			(*novo)->prox = aux->prox;
			aux->prox = (*novo);
			(*novo)->ant = aux;
		}
	}

	if((*lista)->cabeca->dado > (*novo)->dado)
		(*lista)->cabeca = (*novo);
}

struct nold *removeNo(struct lde **lista){
	int x;
	printf("Que elemento deseja remover? ");
	scanf("%d", &x);

	struct nold *aux;
	aux = (*lista)->cabeca;

	while(aux->dado < x)
		aux = aux->prox;

	if(aux->dado == x){
		printf("Removendo elemento...\n");
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;
		printf("Elemento removido.\n\n");
	}
	
	else{
		printf("Elemento inválido\n");
		return 0;
	}

	return aux;
}

void imprimirLista(struct lde **lista){
	struct nold *aux;
	aux = malloc(sizeof(struct nold));
	aux = (*lista)->cabeca;

	while(aux != NULL){
		printf("%d\t", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
	free(aux);
}

int main(){
	struct lde *lista;
	inicializaLista(&lista);
	int opcao = menu();
	while(opcao <= 4 && opcao >0){
		if(opcao == 1){
			struct nold *novo;
			novo = malloc(sizeof(struct nold));
			criaNo(&novo);
			
			if(estaVazia(&lista))
				inserePrimeiro(&lista, &novo);

			if(estaVazia(&lista) == 0)
				insereCabeca(&lista, &novo);

			else
				insereOrdenado(&lista, &novo);
		}

		else if(opcao == 2){
			struct nold *removido;
			removido = removeNo(&lista);
			free(removido);
		}

		else if(opcao == 3){
//			imprimirLista(&lista);
			struct nold *aux;
			aux = lista->cabeca;
	
			while(aux != NULL){
				printf("%d\t", aux->dado);
				aux = aux->prox;
			}
			printf("\n");
			free(aux);
		}
		
		else{
//			destroiLista(&lista);
			free(lista);
			return 0;
		}

		opcao = menu();
	}
	printf("\nOpção inválida\n");
	return 0;
}

