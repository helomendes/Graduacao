#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stddef.h>

struct nodoHash{
    int chave;
    struct nodoHash* prox;
    struct nodoHash* ant;
};

struct aluno{
    char* nome;//nome completo
    char* nomeDinf;//nome de usuário nas servidoras do dinf
    unsigned int grr;
};

struct aluno* getAluno1();

//retorne NULL se o aluno2 não existir
struct aluno* getAluno2();

void imprimirDadosAlunos();

//aloca a tabela hash na memória
struct nodoHash** gerarTabelaHash(size_t tamTabela);

//insere a chave na tabela hash. Duplicatas não são permitidas.
//Retorna o nodo inserido, ou NULL em caso de problemas (ex.: caso a chave seja uma duplicata)
struct nodoHash* inserir(struct nodoHash* tabelaHash[], size_t tamTabela, int chave);

//deleta a tabela hash
void liberarTabelaHash(struct nodoHash* tabelaHash[], size_t tamTabela);

//imprime na tela a tabela completa
void imprimirTabelaHash(struct nodoHash* tabelaHash[], size_t tamTabela);

//busca o nodo com o chave, ou retorna NULL caso tal nodo não exista
struct nodoHash* buscar(struct nodoHash* tabelaHash[], size_t tamTabela, int chave);

//exclui o nodo apontado
void excluir(struct nodoHash* tabelaHash[], size_t tamTabela, struct nodoHash* nodo);

//função hash para calcular a posição no vetor a partir da chave k e do tamanho m do vetor
//retorna sempre um inteiro positivo
int hash(int k, int m);

#endif // TABELA_HASH_H
