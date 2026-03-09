//https://stackoverflow.com/questions/10323060/printing-file-permissions-like-ls-l-using-stat2-in-c
#include "arquivar.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

#define MAX 1024
#define LINESIZE 100

struct dados *criarStruct(char *nome, struct stat informacao, struct dados **raiz)
{
	struct dados* novo = malloc(sizeof(struct dados));
//	novo->nome = malloc
//alocar 1024 bytes pro nome
	novo->nome = nome;
	novo->userID = informacao.st_uid;
	novo->permissao = informacao.st_mode & S_IROTH;
//ler as outras permissoes
	novo->tamanho = informacao.st_size;
	novo->data = malloc(sizeof(char)*15);
	time_t formatar = informacao.st_mtime;
	struct tm* dataFormat = localtime(&formatar);
	strftime(novo->data, sizeof(char)*17, "%d/%m/%Y\t%H:%M", dataFormat);
//rever esse realpath aqui que ta estranho
	char* caminho[MAX];
	novo->localizacao = realpath(nome, *caminho);
	novo->prox = NULL;
	novo->ant = NULL;

	if (!*raiz) {
		*raiz = novo;
	} else {
		struct dados* aux = *raiz;
		while (aux->prox)
			aux = aux->prox;
		aux->prox = novo;
		novo->ant = aux;
	}

	return novo;
}

void destruirLista(struct dados* raiz) {
	if (raiz) {
		while (raiz->prox) {
			raiz = raiz->prox;
			free(raiz->ant);
		}
		free(raiz);
	}
}

long int diretorio(FILE* archive, struct dados** raiz)
{
	struct dados* aux = *raiz;
	long int pont = ftell(archive);
	while (aux) {
		fprintf(archive, "%s\t", aux->nome);
		fprintf(archive, "%d\t", aux->userID);
		fprintf(archive, "%d\t", aux->permissao);
		fprintf(archive, "%ld\t", aux->tamanho);
		fprintf(archive, "%s\t", aux->data);
		fprintf(archive, "%d\t", aux->ordem);
		fprintf(archive, "%s\n", aux->localizacao);
		*raiz = aux;
		aux = aux->prox;		
	}
	return pont;
}

int arquivarI(int argc, char **argv)
{
	FILE *archive;
	archive = fopen(argv[2], "r+");
	if (!archive) {
		perror("Falha ao abrir arquivo.");
		exit(1);
	}
	struct dados *raiz = NULL;

	fseek(archive, 0, SEEK_END);
	if (ftell(archive) == 0) {
		fprintf(archive, "%d\n\n", 100);

		for (int i = 3; i < argc; i++) {
			FILE *membro;
			membro = fopen(argv[i], "r");
			if (!membro) {
				perror("Falha ao abrir arquivo.");
				exit(1);
			}
			struct stat informacao;
			if (stat(argv[i], &informacao) == -1) {
				perror("Falha ao obter informacoes do arquivo.");
				exit(1);
			}
			struct dados* novo = criarStruct(argv[i], informacao, &raiz);
			novo->ordem = i-3;

			char *dado = malloc(sizeof(char)*informacao.st_size);
			//verificar se chegou no fim do arquivo
			fread(dado, sizeof(char), MAX, membro);
			fwrite(dado, sizeof(char), informacao.st_size, archive);
			free(dado);
			fclose(membro);
			fprintf(archive, "\n\n");
		}

		long int ponteiro = diretorio(archive, &raiz);
		fseek(archive, 0, SEEK_SET);
		fwrite(&ponteiro, sizeof(long int), 1, archive);
	} else {
		fseek(archive, 0, SEEK_SET);
		long int ptrDir;
		//(archive, "%ld", &ptrDir);
		fread(&ptrDir, sizeof(long int), 1, archive);
		printf("%ld\n", ptrDir);
		//fseek(archive, 0, ptrDir);

	}

	destruirLista(raiz);

	fclose(archive);
	return 0;
}

int arquivarA(int argc, char **argv) {
	FILE *archive;
	archive = fopen(argv[2], "r+");
	if (!archive) {
		perror("Falha ao abrir arquivo.");
		exit(1);
	}
	struct dados *raiz = NULL;

	fseek(archive, 0, SEEK_END);
	if (ftell(archive) == 0) {
		fprintf(archive, "%d\n\n", 100);

		for (int i = 3; i < argc; i++) {
			FILE *membro;
			membro = fopen(argv[i], "r");
			if (!membro) {
				perror("Falha ao abrir arquivo.");
				exit(1);
			}
			struct stat informacao;
			if (stat(argv[i], &informacao) == -1) {
				perror("Falha ao obter informacoes do arquivo.");
				exit(1);
			}
			struct dados* novo = criarStruct(argv[i], informacao, &raiz);
			novo->ordem = i-3;

			char *dado = malloc(sizeof(char)*informacao.st_size);
			//verificar se chegou no fim do arquivo
			fread(dado, sizeof(char), MAX, membro);
			fwrite(dado, sizeof(char), informacao.st_size, archive);
			free(dado);
			fclose(membro);
			fprintf(archive, "\n\n");
		}

		long int ponteiro = diretorio(archive, &raiz);
		fseek(archive, 0, SEEK_SET);
		fprintf(archive, "%ld\n\n", ponteiro);
	} else {
		fseek(archive, 0, SEEK_SET);
		printf("tem coisa\n");
		printf("ve a data\n");
	}

	destruirLista(raiz);

	fclose(archive);
	return 0;
}