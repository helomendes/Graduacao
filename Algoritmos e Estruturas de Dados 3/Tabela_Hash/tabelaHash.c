#include "tabelaHash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matarProgramaFaltaMemoria() {
    fputs("Falha ao alocar memoria.\n", stderr);
    exit(1);
}

struct aluno* getAluno1() {
    struct aluno* retorno = malloc(sizeof(struct aluno));
    if (!retorno) matarProgramaFaltaMemoria();
    retorno->nome = malloc(sizeof("Heloisa Benedet Mendes"));  // sizeof conta o \0
    if (!retorno->nome)
        matarProgramaFaltaMemoria();
    retorno->nomeDinf = malloc(sizeof("hbm22"));
    if (!(retorno->nomeDinf))
        matarProgramaFaltaMemoria();

    strcpy(retorno->nome, "Heloisa Benedet Mendes");
    strcpy(retorno->nomeDinf, "hbm22");
    retorno->grr = 20221248;

    return retorno;
}

struct aluno* getAluno2() {
    return NULL;
}

void imprimirDadosAlunos() {
    struct aluno* aluno = getAluno1();

    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);

    aluno = getAluno2();
    if (!aluno) return;

    printf("...E... \n\n");
    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);
}

struct nodoHash** gerarTabelaHash(size_t tamTabela){
    struct nodoHash** tabelaHash = calloc(tamTabela, sizeof(struct nodoHash));
    if (!tabelaHash) matarProgramaFaltaMemoria();
    return tabelaHash;
}

struct nodoHash* inserir(struct nodoHash* tabelaHash[], size_t tamTabela, int chave) {
	struct nodoHash* insere = calloc(1, sizeof(struct nodoHash));
    if (!insere) matarProgramaFaltaMemoria();
	insere->chave = chave;
    if (buscar(tabelaHash, tamTabela, chave) == NULL) {
       	int h = hash(chave, tamTabela);
        if (tabelaHash[h] == NULL) {
            tabelaHash[h] = insere;
        } else {
            struct nodoHash* aux = tabelaHash[h];
            while(aux->prox)
                aux = aux->prox;
            aux->prox = insere;
            insere->ant = aux;
        }
        return insere;
    }
    free(insere);
    return NULL;
}

void liberarTabelaHash(struct nodoHash* tabelaHash[], size_t tamTabela){
    struct nodoHash* aux;
    for (size_t i = 0; i < tamTabela; i++) {
        aux = tabelaHash[i];
        while(aux && aux->prox) {
            aux = aux->prox;
            free(aux->ant);
        }
        free(aux);
	}
    free(tabelaHash);
}

void imprimirTabelaHash(struct nodoHash* tabelaHash[], size_t tamTabela){
    struct nodoHash* aux;
    for (size_t k = 0; k < tamTabela; k++) {
        printf("%ld ", k);
        aux = tabelaHash[k];
        while(aux) {
            printf("[%d] -> ", aux->chave);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

struct nodoHash* buscar(struct nodoHash* tabelaHash[], size_t tamTabela, int chave){
	struct nodoHash* busca = tabelaHash[hash(chave, tamTabela)];
    	while (busca) {
        	if (busca->chave == chave)
            		return busca;
        	busca = busca->prox;
    	}
    	return NULL;
}

void excluir(struct nodoHash* tabelaHash[], size_t tamTabela, struct nodoHash* nodo){
    if (nodo->ant) {
        nodo->ant->prox = nodo->prox;
        if (nodo->prox)
            nodo->prox->ant = nodo->ant;
    } else {
	    tabelaHash[hash(nodo->chave, tamTabela)] = nodo->prox;
        if (nodo->prox)
            nodo->prox->ant = NULL;
    }
    free(nodo);
}

int hash(int k, int m) {
    int h;
    h = k % m;
    if (h < 0)
        h = h * (-1);
    return h;
}