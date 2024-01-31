#ifndef ARQUIVAR_H
#define ARQUIVAR_H

struct dados {
	char *nome;
	int userID;
	int permissao;
	long int tamanho;
	char *data;
	int ordem;
//ponteiro no arquivo
	char *localizacao;
	struct dados *prox;
	struct dados *ant;
};

//cria e inicializa uma estrutura de dados com as informações da estrutura stat, ajustando os ponteiros e sua posição na lista
//parametros: o nome do arquivo membro, a estrutura stat de informações e o ponteiro para o início da lista
//retorna a estrutura criada
struct dados *criarStruct();

//desaloca a lista duplamente encadeada
//parametros: struct dados* raiz da lista
void destruirLista();

//escreve os dados da lista no archive e destrói a lista
//parametros: o arquivo a ser escrito e o ponteiro para o início da lista
//retorna o ponteiro onde começa a área de diretório final do archive
long int diretorio();

//passa os conteúdos dos arquivos membros para o archive
//parametros: um inteiro com o número e o vetor de argumentos passados no main
//retorna 0 se o arquivo for escrito corretamente, e 1 caso dê erro ao abrir/criar os arquivos ou obter as informações dos membros
int arquivarI();

int arquivarA();

#endif
