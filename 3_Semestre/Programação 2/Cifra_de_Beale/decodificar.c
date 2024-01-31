#include "decodificar.h"

char encontrarCode(FILE *arqC, int code) {
	char c = 0;
	char x = getc(arqC);
	int num = 0;
	int atual;
	rewind(arqC);

	//enquanto nao chega ao fim do arquivo
	while(!feof(arqC)) {
		x = getc(arqC);
		//enquanto x nao for espaço ou new line
		while (x != ' ' && x != '\n') {
			atual = x - 48;
			num = num*10 + atual;
			x = getc(arqC);
		}
		//encontrou um espaço ou um newline
		//verifica se encontrou o codigo
		if (num == code) {
			c = x;
			//retrocede até encontrar o :
			while (c != ':') {
				fseek(arqC, -2, SEEK_CUR);
				c = getc(arqC);
			}
			fseek(arqC, -2, SEEK_CUR);
			c = getc(arqC);
			return c;
		}
		//nao encontrou o codigo
		num = 0;
	}
	return '\0';
}

int decodificarMensagem(char *mC, char *mD, char *lC, char *aC) {
	FILE *mensCod;
	FILE *mensDec;
	FILE *livroC;
	FILE *arqC;

	mensCod = fopen(mC, "r");
	if (!mensCod) {
		perror("Falha ao abrir arquivo");
		exit(1);
	}
	mensDec = fopen(mD, "w");
	if (!mensDec) {
		perror("Falha ao criar arquivo");
		exit(1);
	}
	if (lC != NULL) {
		livroC = fopen(lC, "r");
		if (!livroC) {
			perror("Falha ao abrir arquivo");
			exit(1);
		}
		aC = "ArquivoDeChaves";
		arqC = fopen(aC, "w+");
		if (!livroC) {
			perror("Falha ao criar arquivo");
			exit(1);
		}
		int checkArq;
		checkArq = arquivoDeChaves(livroC, arqC);
		if (checkArq) {
			printf("Falha na criação do arquivo de chaves\n");
			exit(1);
		}
	} else if (aC != NULL) {
		arqC = fopen(aC, "r");
		if (!arqC) {
			perror("Falha ao abrir arquivo");
			exit(1);
		}
	}

	fseek(mensCod, 0, SEEK_SET);
	fseek(mensDec, 0, SEEK_SET);
	if (lC != NULL)
		fseek(livroC, 0, SEEK_SET);
	fseek(arqC, 0, SEEK_SET);

	char c = getc(mensCod);
	int code = 0;
	while(!feof(mensCod)) {
		code = 0;
		while (c != ' ' && c != '\n') {
			if (c >= '0' && c <= '9') {
				code = code*10 + c - 48;
			} else if (c == '-') {
				c = getc(mensCod);
				fprintf(mensDec, " ");
			} else if (c == '*') {
				fprintf(mensDec, "*");
			}
			c = getc(mensCod);
		}
		c = getc(mensCod);
		if (code) {
			char caractere;
			caractere = encontrarCode(arqC, code);
			fprintf(mensDec, "%c", caractere);
		}
	}

	fclose(mensCod);
	fclose(mensDec);
	if (lC != NULL) {
		remove(aC);
		fclose(livroC);
	}
	fclose(arqC);

	return 0;
}
