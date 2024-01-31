#include <stdio.h>
#define LIN 12
#define COL 4

void preencherMatriz(char onibus[LIN][COL])
{
	for(int i = 0; i < LIN; i++)
		for(int j = 0; j < COL; j++)
			onibus[i][j] = 'L';
}

void imprimirMatriz(char onibus[LIN][COL])
{
	for(int i = 0; i < LIN; i++)
	{
		for(int j = 0; j < COL; j++)
			printf("%c\t", onibus[i][j]);
		printf("\n");
	}
}

int main()
{
	char onibus[LIN][COL];
	preencherMatriz(onibus);
	imprimirMatriz(onibus);
	printf("\n");
	onibus[5][4] = 'R';
	imprimirMatriz(onibus);
	return 0;
}
