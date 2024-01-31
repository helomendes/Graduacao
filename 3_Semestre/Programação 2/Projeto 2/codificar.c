#include "codificar.h"

struct vetor *criarVetor() {
	struct vetor *novo;
	novo = malloc(sizeof(struct vetor));
	novo->n = '\0';
	novo->prox = NULL;
	novo->ant = NULL;

	return novo;
}

int adicionarVetor(struct vetor *codes, int num) {
	if (codes->n == '\0') {
		codes->n = num;
		return 0;
	}
	struct vetor *novo;
	novo = criarVetor();
	novo-> n = num;
	struct vetor *aux = codes;
	while (aux->ant != NULL)
		aux = aux->ant;
	if (num < aux->n) {
		novo->prox = aux;
		aux->ant = novo;
		return 0;
	} else if (num > aux->n) {
		while (aux->prox != NULL)
			aux = aux->prox;
		novo->ant = aux;
		aux->prox = novo;
		return 0;
	}
	return 0;
}

void destruirVetor(struct vetor *codes) {
 	struct vetor *v = codes;
        struct vetor *aux;
        while (v->prox != NULL) {
                aux = v->prox;
                free(v);
                v = aux;
        }
	free(v);
 }


int codificar(FILE *mensO, FILE *chave, FILE *mensC) {
	fseek(mensO, 0, SEEK_SET);
	fseek(chave, 0, SEEK_SET);
	fseek(mensC, 0, SEEK_SET);
	char cMens = 0;
	char cChave = 0;
	long int num = 0;
	int atual = 0;
	int cont = 0;

	while (!feof(mensO)) {
		cMens = lerChar(mensO);
		//se o char for espaço
		if (cMens == ' ') {
			fprintf(mensC, "-1 ");
		//se não for espaço
		} else {
			//procura o char na lista de chaves
			cChave = getc(chave);
			while (cMens != cChave && !feof(chave))
				cChave = getc(chave);
			//se ele não está na lista de chaves
			if (feof(chave)) {
				fprintf(mensC, "* ");
			//ele está na lista de chaves
			} else {
				//cria uma lista para as posições
				struct vetor *codes;
				codes = criarVetor();
				//posiciona o ponteiro
				fseek(chave, 1, SEEK_CUR);
				cChave = getc(chave);
				//enquanto não chegar ao fim da linha
				while (cChave != '\n') {
					num = 0;
					cChave = getc(chave);
					//enquanto não encontrar o espaço ou o fim da linha
					while (cChave != ' ' && cChave != '\n') {
						atual = cChave - 48;
						num = num*10 + atual;
						cChave = getc(chave);
					}
					adicionarVetor(codes, num);
					cont++;
				}
				//chegou ao fim da linha
				//tem a lista com todos os cods do char e quantos cods existem
				//randomiza um codigo da lista
				srand((unsigned)time(NULL));
				int r = 1 + (rand()%cont);
				struct vetor *pont = codes;
				while (pont->ant != NULL)
					pont = pont->ant;
				for (int i = 0; i < r; i++) {
					if (pont->prox != NULL)
						pont = pont->prox;
					else
						i = r;
				}
				fprintf(mensC, "%ld ", pont->n);
				destruirVetor(codes);
			}
		}
		rewind(chave);
		cont = 0;
	}

	return 0;
}

int codificarMensagem(char *lC, char *mO, char *mC, char *aC) {
	FILE *livroC;
	FILE *arqC;
	FILE *mensOrig;
	FILE *mensCod;

	livroC = fopen(lC, "r");
	if (!livroC) {
		perror("Falha ao abrir arquivo");
		exit(1);
	}
	arqC = fopen(aC, "w+");
	if (!arqC) {
		perror("Falha ao abrir arquivo");
		exit(1);
	}
	mensOrig = fopen(mO, "r");
	if (!mensOrig) {
		perror("Falha ao abrir arquivo");
		exit(1);
	}
	mensCod = fopen(mC, "w");
	if (!mensCod) {
		perror("Falha ao criar arquivo");
		exit(1);
	}

	int checkArqChaves;
	checkArqChaves = arquivoDeChaves(livroC, arqC);
	if (checkArqChaves) {
		printf("Falha na criação do arquivo de chaves\n");
		exit(1);
	}

	if (arqC)
		codificar(mensOrig, arqC, mensCod);

	char option = 'x';
	while (option != 'y' && option != 'n') {
		printf("Deseja salvar o arquivo de chaves em %s? (y/n) ", aC);
		scanf("%c", &option);
		getchar();
		if (option != 'y' && option != 'n')
			printf("Inválido.\n");
	}
	if (option == 'y') {
		printf("Arquivo salvo.\n");
	} else if (option == 'n') {
		remove(aC);
	}

	fclose(livroC);
	fclose(arqC);
	fclose(mensOrig);
	fclose(mensCod);

	return 0;
}
