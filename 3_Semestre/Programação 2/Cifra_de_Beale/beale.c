#include "codificar.h"
#include "decodificar.h"

int main(int argc, char **argv){
	if (argc == 1)
		return 1;

	int flag_e = 0;
	
	char *c1 = argv[1];
	char *c4 = argv[4];
	char C1 = c1[1];
	char C4 = c4[1];

	char *lC = NULL;
	char *mO = NULL;
	char *mC = NULL;
	char *mD = NULL;
	char *aC = NULL;
	
	if (C1 == 'e') {
		flag_e = 1;
		lC = argv[3];
		mO = argv[5];
		mC = argv[7];
		aC = argv[9];
	} else if (C1 == 'd') {
		mC = argv[3];
		mD = argv[7];
		if (C4 == 'c') {
			aC = argv[5];
		} else if (C4 == 'b') {
			lC = argv[5];
		}
	}
	
	if (flag_e) {
		codificarMensagem(lC, mO, mC, aC);
		return 0;
	} else {
		decodificarMensagem(mC, mD, lC, aC);
		return 0;
	}
	
	return 0;
}
