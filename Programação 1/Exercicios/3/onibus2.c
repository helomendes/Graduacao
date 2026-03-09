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

char encontrarAssento(char onibus[LIN][COL], int assento, int *l, int *c)
{
	int linha, coluna;
	if (assento == 0)
	{
		linha = 0;
		coluna = 0;
	}
	if (assento % 4 == 0)
	{
		linha = (assento / 4);
		coluna = 3;
	}
	
	else
	{
		linha = (assento / 4)+1;
		if (assento / 2 == 0)
			coluna = 1;
		else if (assento % 2 == 1)
			coluna = 0;
		else if (assento % 2 == 3)
			coluna = 2;
	}
	
	*l = linha;
	*c = coluna;

	return onibus[linha][coluna];
}


int verificarAssento(char onibus[LIN][COL], int assento)
{
	int *l, *c;
	if (encontrarAssento(onibus, assento, l, c) == 'L')
		printf("Assento livre.\n");
	
	else
	{
		printf("Assento indisponível.\n");
		return 0;
	}
	
	return 1;
}

int reservarAssento(char onibus[LIN][COL], int assento)
{
	int *l, *c;
	encontrarAssento(onibus, assento, l, c);
        onibus[*l][*c] = 'R';
	
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
	int assento, linha, coluna;
	char opcao;
	char onibus [LIN][COL];
	
	preencherMatriz(onibus);
	
	printf("Insira a opção desejada:\n");
	printf("a. Verificar se o assento está livre.\nb. Reservar um assento livre.\nc. Imprimir o mapa de assentos.\n");
	scanf("%c", &opcao);
	
	if(opcao == 'a')
	{
		int aux;
		int *l, *c;
		
		//le o assento desejado
		printf("Qual assento deseja verificar?\n");
		scanf("%d", &assento);
		
		aux = encontrarAssento(onibus, assento, l, c);

		//ve se o assento escolhido é o do motorista ou o banheiro
		if(aux == onibus[0][0] || aux == onibus[11][3])
		{
			printf("Assento indisponível\n");
			return 0;
		}

		verificarAssento(onibus, assento);
	}
	
	else if (opcao == 'b')
	{	
		//ve qual o assento desejado
		printf("Qual assento gostaria de reservar?\n");
		scanf("%d", &assento);	
		
		//ve se o assento está ocupado (0, encerra o programa) ou livre (1, reserva o assento)
		if (verificarAssento(onibus, assento) == 0)
			return 0;
		else
			reservarAssento(onibus, assento);
	}
	
	else if (opcao == 'c')
		imprimirAssento(onibus);
	
	else
		printf("Opção inválida.\n");
	
	return 0;
}

