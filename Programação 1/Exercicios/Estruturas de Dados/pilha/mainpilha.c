#include <stdio.h>
#include <stdlib.h>
#include "pilhalib.h"

struct nop{
	int dado;
	struct nop *prox;
};//estrutura do no (cada uma das caixas)

struct pilha{
	struct nop *topo;
};//a pilha deve sempre ter um topo

void destruirPilha(struct pilha **empilhar){
	while((*empilhar)->topo != NULL){
		free((*empilhar)->topo);
		(*empilhar)->topo = (*empilhar)->topo->prox;
	}
}


int menu(){
	int op;
	printf("\nInsira a opção desejada:\n0\tpush\n1\tpop\n2\tprint\n3\tsair\n");
	scanf("%d", &op);
	return op;
}

int main(){
	int opcao = 0;
	int quant = 0;
	struct pilha *empilha; //cria a estrutura de 'empilhação'
	empilha = malloc(sizeof(struct pilha)); //aloca espaço
	while(opcao < 4 && opcao > -1){
		opcao = menu();
		if (opcao == 0){
			push(&empilha, quant);//adiciona elementos à pilha
			quant++;
		}
		else if (opcao ==1){
			pop(&empilha);//tira o ultimo elemento
			quant--;
		}
		else if (opcao == 2){
			printf("\nImprimindo a pilha:\n");
			struct nop *aux;
			aux = malloc(sizeof(struct nop));
			aux = empilha->topo;
			while(aux != NULL){
				printf("%d\n", aux->dado);
				aux = aux->prox;
			}
			free(aux);
		}
		else{
			destruirPilha(&empilha);
			free(empilha); //libera o espaço utilizado
			return 0;
		}
	}
	return 0;
}
