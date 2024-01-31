#include <stdio.h>
#define LIN 12
#define COL 4

void preencherMatriz(char onibus[LIN][COL])
{
	char x = 'L';
	for (int i = 0; i < LIN; i++)
	{
		for (int j = 0; j < COL; j++)
			onibus[i][j] = x;
	}
}

int encontrarAssento(char onibus[LIN][COL], int assento, int *linha, int *coluna)
{
	if (assento % 4 == 0)
	{
		*linha = (assento / 4);
		*coluna = 3;
	}
	
	else
	{
		*linha = (assento / 4)+1;
		if (assento / 2 == 0)
			*coluna = 1;
		else if (assento % 2 == 1)
			*coluna = 0;
		else if (assento % 2 == 3)
			*coluna = 2;
	}
	
	return onibus[*linha][*coluna];
}


int verificarAssento(char onibus[LIN][COL], int assento, int *linha, int *coluna)
{
	if (encontrarAssento(onibus, assento, *linha, *coluna) == 'L')
		printf("Assento livre.\n");
	
	else
	{
		printf("Assento indisponível.\n");
		return 0;
	}
	
	return 1;
}

int reservarAssento(char onibus[LIN][COL], int assento, int *linha, int *coluna)
{
	encontrarAssento(onibus, assento, *linha, *coluna);
	onibus[*linha][*coluna]= 'R';
	
	printf("Assento reservado.\n");
	
	return 0;
}

void imprimirAssento(char onibus[LIN][COL])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%c\t", onibus[i][j]);
		printf("\n");
	}
}


int main ()
{
	int assento, *linha = 0, *coluna = 0;
	char opcao;
	char onibus [LIN][COL];
	
	preencherMatriz(onibus);
	
	printf("Insira a opção desejada:\n");
	printf("a. Verificar se o assento está livre.\nb. Reservar um assento livre.\nc. Imprimir o mapa de assentos.\n");
	scanf("%c", &opcao);
	
	if(opcao == 'a')
	{
		printf("Qual assento deseja verificar?\n");
		scanf("%d", &assento);
		if(assento == onibus[0][0] || assento == onibus[11][3])
		{
			printf("Assento indisponível\n");
			return 0;
		}
		verificarAssento(onibus, assento, *linha, *coluna);
	}
	
	else if (opcao == 'b')
	{
		int ver;
		printf("Qual assento gostaria de reservar?\n");
		scanf("%d", &assento);	
		ver = verificarAssento(onibus, assento,*linha, *coluna);
		if (ver == 0)
			return 0;
		else
			reservarAssento(onibus, assento, *linha, *coluna);
	}
	
	else if (opcao == 'c')
		imprimirAssento(onibus);
	
	else
		printf("Opção inválida.\n");
	
	return 0;
}

