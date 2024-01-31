#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "arquivar.h"

void help()
{
	printf("VINA++\t\t\t\t\tUser Commands\n\n");
	printf("NOME\n\tvina++\n\n");
	printf("SINOPSE\n\tvina++ <opcao> <archive> [membro1 membro2 ...]\n\n");
	printf("DESCRICAO\n\tArquivador basico. Salva em sequencia uma colecao de arquivos (membros) dentro de outro arquivo (archive). Permite recuperar os arquivos originais individualmente.\n\n");
	printf("\t-i\n\t\tinsere/acrescenta (com substituicao) um ou mais membros ao archive\n\n");
	printf("\t-a\n\t\t-i, mas a substituicao ocorre apenas caso o parametro seja mais recente que o arquivado\n\n");
	printf("\t-m target\n\t\tmove o membro indicado na linha de comando para imediatamente depois do membro target existente em archive\n\n");
	printf("\t-x\n\t\textrai os membros indicados de archive\n\n");
	printf("\t-r\n\t\tremove os membros indicados de archive\n\n");
	printf("\t-c\n\t\tlista o conteúdo de archive\n\n");
	printf("\t-h\n\t\tajuda\n\n");
}

int main(int argc, char **argv){
	//char *target = NULL;
	int option;

	opterr = 0;

	while((option = getopt(argc, argv, "iam:xrch")) != -1)
		switch(option) {
			case 'i':
				//insere/acrescenta um ou mais membros ao archive, deve ser substituido
				arquivarI(argc, argv);
				break;
			case 'a':
				//igual, mas a substituição só ocorre se o parametro for mais recente que o arquivado
				arquivarA(argc, argv);
				break;
			case 'm':
				//move o membro na linha de comando para imediatamente depois do membro target
				//target = optarg;
				break;
			case 'x':
				//extrai os membros indicados de archive
				break;
			case 'r':
				//remove os membros indicados de archive
				break;
			case 'c':
				//lista o conteudo de archive em ordem
				break;
			case 'h':
				//imprime uma pequena mensagem de ajuda com as opções disponiveis e encerra
				help();
				break;
			default:
				fprintf(stderr, "Usage: %s -i -a -m value -x -r -c -h\n", argv[0]);
				exit(1);
		}

	return 0;
}
