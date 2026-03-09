#include "movimentar.h"

int movimentar(char* target) {
    FILE* archive;
    FILE* targ;
    FILE* membro;

    archive = fopen(argv[3], "a+");
    if (!archive) {
		perror("Falha ao criar arquivo.");
		exit(1);
	}
    targ = fopen(target, "r");
    if (!targ) {
		perror("Falha ao criar arquivo.");
		exit(1);
	}
    membro = fopen(argv[4], "r");
    if (!membro) {
		perror("Falha ao criar arquivo.");
		exit(1);
	}



    fclose(archive);
    fclose(targ);
    fclose(membro);
}