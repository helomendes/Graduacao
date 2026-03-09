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

char menu(char op)
{
	printf("Insira a opção desejada:\na. Verificar assento\nb. Reservar assento livre\nc. Imprimir mapa de assentos\nd. Sair\n");
	scanf(" %c", &op);
	return op;
}

char encontrarAssento(char onibus[LIN][COL], int assento, int tipo)
{
	int linha, coluna;
	if (assento%4 == 0)
	{
		coluna = 3;
		linha = (assento/4)-1;
	}
	else if (assento%4 == 1)
	{
		coluna = 0;
		linha = (assento-1)/4;
	}
	else if (assento%2 == 0)
	{
		coluna = 1;
		linha = (assento/2)/2;
	}
	else if (assento%4 == 3)
	{
		coluna = 2;
		linha = (assento-3)/4;
	}
	
	if (tipo == 0)
		return onibus[linha][coluna];
	else if (tipo == 1)
		return linha;
	else
		return coluna;
}

int verificarAssento(char onibus[LIN][COL], int assento)
{
	char confere;
	if (assento == 0 || assento == 49)
		return 0;
	int tipo = 0;
	confere = encontrarAssento(onibus, assento, tipo);
	if (confere == 'L')
		return 1;
	else
		return 0;
}

int reservarAssento(char onibus[LIN][COL], int assento)
{
	int l, c;
	if (assento == 0 || assento == 49 || verificarAssento(onibus, assento) == 0)
	{
		printf("\nASSENTO INDISPONÍVEL.\n\n");
		return 0;
	}
	int tipo = 1;
	l = encontrarAssento(onibus, assento, tipo);
	tipo = 2;
	c = encontrarAssento(onibus, assento, tipo);
	onibus[l][c] = 'R';
	printf("\nASSENTO RESERVADO COM SUCESSO!\n\n");
	return 0;
}

int main()
{
	int laco = 0;
	int assento;
	char op;
	char onibus[LIN][COL];

	preencherMatriz(onibus);

	while (laco == 0)
	{
		op = menu(op);
	
		if (op == 'a')
		{
			printf("Insira o assento desejado: ");
			scanf(" %d", &assento);
		
			if (verificarAssento(onibus, assento) == 0)
				printf("\nASSENTO INDISPONÍVEL.\n\n");
			else
				printf("\nASSENTO DISPONÍVEL.\n\n");
		
		}
	
		else if (op == 'b')
		{
			printf("Insira o assento desejado: ");
			scanf(" %d", &assento);

			reservarAssento(onibus, assento);
		}
	
		else if (op == 'c')
			imprimirMatriz(onibus);

		else if (op == 'd')
			laco = 1;
		else
			printf("OPÇÃO INVÁLIDA.\n");
	}
	return 0;
}
