#include <stdio.h>

#define M 20
#define N 18
#define PAREDE 64
#define PASSAGEM 32
#define PASSOU 46

void imprimirLabirinto(int labirinto[][N]);
void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim);
int saida(int labirinto[][N], int l, int c, int lfim, int cfim);

int main(){
	int labirinto[M][N];
	int linhaInicio, colInicio, linhaFim, colFim;
	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);
	imprimirLabirinto(labirinto);
	printf("\nSaída:\n");
	saida(labirinto, linhaInicio, colInicio, linhaFim, colFim);
	return 0;
}

void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim){
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for(int i=0; i < M; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int labirinto[][N]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%c",labirinto[i][j]);
		}
		printf("\n");
	}
}

int saida(int labirinto[][N], int l, int c, int lfim, int cfim){
	if (l >= lfim || c >= cfim){
		imprimirLabirinto(labirinto);
		return 0;
	}

	if(labirinto[l][c] == PASSAGEM){
		labirinto[l][c] = PASSOU;
		saida(labirinto, l, c, lfim, cfim);
	}

	else if(labirinto[l][c+1] == PASSAGEM){
		labirinto[l][c+1] = PASSOU;
		saida(labirinto, l, c+1, lfim, cfim);
	}

	else if(labirinto[l+1][c] == PASSAGEM){
		labirinto[l+1][c] = PASSOU;
		saida(labirinto, l+1, c, lfim, cfim);
	}

	else if(labirinto[l][c-1] == PASSAGEM){
		labirinto[l][c-1] = PASSOU;
		saida(labirinto, l, c-1, lfim, cfim);
	}

	else if(labirinto[l-1][c] == PASSAGEM){
		labirinto[l-1][c] = PASSOU;
		saida(labirinto, l-1, c, lfim, cfim);
	}

	imprimirLabirinto(labirinto);
	return 0;
}
