#include <stdio.h>
#include <likwid.h>
#include "EG.h"
#include "GS.h"
#include "toolbox.h"

int main() {
	struct SL *SL = inicializar_SL();
	struct SL *copia_SL = copiar_SL(SL);
	
	struct tridiagonal *SL3d = inicializar_3diagonal(SL);
	struct tridiagonal *copia_SL3d = copiar_SL3d(SL3d);
	
	LIKWID_MARKER_INIT;
	
	executar_SL(SL, copia_SL, "EG_classico", eliminacao_gauss);
	executar_SL(SL, copia_SL, "GS_classico", gauss_seidel);
	executar_SL3d(SL3d, copia_SL3d, "EG_3-diagonal", eliminacao_gauss_3diagonal);
	executar_SL3d(SL3d, copia_SL3d, "GS_3-diagonal", gauss_seidel_3diagonal);
	
	LIKWID_MARKER_CLOSE;

	free_SL(SL);
	free_SL(copia_SL);
	free_SL3d(SL3d);
	free_SL3d(copia_SL3d);

	return 0;
}
