#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "mapa.h"
#include "filacerto.h"
#include "pilhascerto.h"
#include "structs.h"
#include "cores.h"

#define LIN 10
#define COL 27

void criarMapa(char mapa[LIN][COL]){
//inicialização do mapa
	for(int i = 0; i<LIN; i++)
		for(int j = 0; j<COL; j++)
			mapa[i][j] = ' ';

//paredes superiores
	for(int j = 0; j<COL; j++){
		mapa[0][j] = '-';
		mapa[LIN-1][j] = '-';
	}

//paredes laterais
	for(int i = 0; i<LIN; i++){
		mapa[i][0] = '|';
		mapa[i][COL-1] = '|';
	}

//ponto de entrega
	mapa[0][COL/2] = '@';
	mapa[0][(COL/2)-1] = '|';
	mapa[0][(COL/2)+1] = '|';

//lixeira
	mapa[2][COL-3] = 'o';

//outra lixeira
	mapa[5][COL-3]= 'x';

//estações
	//pães parte de baixo
	mapa[LIN-2][2] = '[';
	mapa[LIN-2][3] = 'p';
	mapa[LIN-2][4] = ']';
	//pães parte de cima
	mapa[LIN-2][COL-3] = ']';
	mapa[LIN-2][COL-4] = 'P';
	mapa[LIN-2][COL-5] = '[';
	//hamburguer
	mapa[LIN-2][7] = '[';
	mapa[LIN-2][8] = 'H';
	mapa[LIN-2][9] = ']';
	//queijo
	mapa[LIN-2][12] = '[';
	mapa[LIN-2][13] = 'Q';
	mapa[LIN-2][14] = ']';
	//salada
	mapa[LIN-2][17] = '[';
	mapa[LIN-2][18] = 'S';
	mapa[LIN-2][19] = ']';
	//refrigetante
	mapa[2][2] = '[';
	mapa[2][3] = 'R';
	mapa[2][4] = ']';
	//fritas
	mapa[5][2] = '[';
	mapa[5][3] = 'F';
	mapa[5][4] = ']';

//cantos
	mapa[0][0] = '#';
	mapa[0][COL-1] = '#';
	mapa[LIN-1][0] = '#';
	mapa[LIN-1][COL-1] = '#';

}

void receitas(){
//receitas das refeições
	printf("\t\t\t\t\t\t\tRECEITAS:\n");
	printf("\t\t\t\t\t\t\t#-----------------------------------------------#\n");
	printf("\t\t\t\t\t\t\t|\tX-BURGER:\t[p][H][Q][P]\t\t|\n");
	printf("\t\t\t\t\t\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t|\tX-SALADA:\t[p][H][S][P]\t\t|\n");
	printf("\t\t\t\t\t\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t|\tCOMBO 1:\t[p][H][Q][P][F][R]\t|\n");
	printf("\t\t\t\t\t\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t|\tCOMBO 2:\t[p][H][S][P][F][R]\t|\n");
	printf("\t\t\t\t\t\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t|\tVEGETARIANO:\t[p][Q][P][F][R]\t\t|\n");
	printf("\t\t\t\t\t\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t\t\t\t|\tVEGANO:\t\t[S][F][R]\t\t|\n");
	printf("\t\t\t\t\t\t\t#-----------------------------------------------#\n\n");
}

int headerSleep(int x){		//animação de inicio do jogo
	if(x == 0)
		return 0;
	system("clear");	
	for(int i = 0; i<=x; i++)
		printf("\n");
		usleep(500000);
		brightred();
		printf("\t\t\t\t\t\t\tOOOo  OOOOO       OOOo  O   O OOOo   OOo  OOOOO OOOo\n");
		reset();
		usleep(500000);
		brightblue();
		printf("\t\t\t\t\t\t\tO   O O           O   O O   O O   O O     O     O   O\n");
		reset();
		usleep(500000);
		brightgreen();
		printf("\t\t\t\t\t\t\tO   O OOOO  ooooo OOOO  O   O OOO°  O oOO OOOO  OOO°\n");
		reset();
		usleep(500000);
		brightyellow();
		printf("\t\t\t\t\t\t\tO   O O           O   O O   O O  O  O   o O     O  O\n");
		reset();
		usleep(500000);
		brightpurple();
		printf("\t\t\t\t\t\t\tOOO°  OOOOO       OOO°   OOO  O   O  OO°  OOOOO O   O\n");
		usleep(500000);
		reset();
		for(int i = x; i >= 0; i--){
			header(i);
			usleep(400000);
			i--;
		}
	usleep(500000);
}

void inicio(){
	system("clear");
	for(int i = 0; i<18; i++)
		printf("\n");
	brightcyan();
	printf("\t\t\t\t\t\tOOOo  OOOo  OOOOO oOOOO oOOOO     OOOOO O   O OOOOO OOOOO OOOo\n");	
	printf("\t\t\t\t\t\tO   O O   O O     O     O         O     OO  O   O   O     O   O\n");
	printf("\t\t\t\t\t\tOOO°  OOO°  OOOO   °Oo   °Oo      OOOO  O O O   O   OOOO  OOO°\n");
	printf("\t\t\t\t\t\tO     O  O  O        °o    °o     O     O  OO   O   O     O  O\n");
	printf("\t\t\t\t\t\tO     O   O OOOOO OOOO° OOOO°     OOOOO O   O   O   OOOOO O   O\n");
	reset();
	for(int i = 0; i<20; i++)
		printf("\n");
}

int header(int x){
	system("clear");
	for(int i = 0; i <= x; i++)
		printf("\n");
	printf("\t\t\t\t\t\t\tOOOo  OOOOO       OOOo  O   O OOOo   OOo  OOOOO OOOo\n");
	printf("\t\t\t\t\t\t\tO   O O           O   O O   O O   O O     O     O   O\n");
	printf("\t\t\t\t\t\t\tO   O OOOO  ooooo OOOO  O   O OOO°  O oOO OOOO  OOO°\n");
	printf("\t\t\t\t\t\t\tO   O O           O   O O   O O  O  O   o O     O  O\n");
	printf("\t\t\t\t\t\t\tOOO°  OOOOO       OOO°   OOO  O   O  OO°  OOOOO O   O\n\n");
}

void imprimirMapa(char mapa[LIN][COL], int chapeiro[], int pontos, double tempo, struct fila *ordem_pedido, struct pilha *refeicao){	//imprime o mapa em loop
	header(0);
	printf("\t\t\t\t\t\t\t\t\tuse as teclsa WASD\n\n");
	Bred();
	printf("\t\t\t\t\t\t\t\tO RESTAURANTE FECHA EM 300 SEGUNDOS\n\n");
	reset();
	receitas();
	printf("\t\t\t\t\t\t\tPEDIDOS:\n\n\t\t\t\t");
	imprimirTodosPedidos(ordem_pedido);
	printf("\n");
	int t = tempo*1000;
	printf("\n\t\t\t\t\t\t\t\tPONTUAÇÃO: %d\tTEMPO: %d\n", pontos, t);
	mapa[chapeiro[0]][chapeiro[1]] = '&';
	for(int i = 0; i<LIN; i++){
		printf("\t\t\t\t\t\t\t\t");
		for(int j = 0; j<COL; j++)
			if ((j== 12 && i==LIN-2)|| (j ==13 && i==LIN-2 )|| (j==14 && i==LIN-2)){
				Byellow();
				printf("%c", mapa[i][j]);
				reset();
			}
			else if ((j==17 && i==LIN-2)|| (j ==18 && i==LIN-2 )|| (j==19 && i==LIN-2)){
				Bgreen();
				printf("%c", mapa[i][j]);
				reset();
			}
			else if ((j==7 && i==LIN-2)|| (j ==8 && i==LIN-2 )|| (j==9 && i==LIN-2)){
				brightred();
				printf("%c", mapa[i][j]);
				reset();
			}
			else if((j==2 && i==5)|| (j ==3 && i==5 )|| (j==4 && i==5)){
				brightyellow();
				printf("%c", mapa[i][j]);
				reset();
			}
			else if (((j==2 || j ==COL-3) && i==LIN-2)|| ((j==3 || j==COL-4) && i==LIN-2 )|| ((j==4 || j==COL-5) && i==LIN-2)){
				Bwhite();
				printf("%c", mapa[i][j]);
				reset();
			}
			else if((j==2 && i==2)|| (j ==3 && i==2 )|| (j==4 && i==2)){
				Bcyan();
				printf("%c", mapa[i][j]);
				reset();
			}
			else if((j==COL/2 && i==0)|| (j ==COL/2+1 && i==0 )|| (j==COL/2-1 && i==0)){
				Bpurple();
				printf("%c", mapa[i][j]);
				reset();
			}
			else if((j==COL-3 && i==2)|| (j ==COL-3 && i==5 )){
				black();
				printf("%c", mapa[i][j]);
				reset();
			}
			else {
				printf("%c", mapa[i][j]);
			}
		printf("\n");
	}
	mapa[chapeiro[0]][chapeiro[1]] = ' ';
	printf("\n\t\t\t\t\t\t\tINVENTÁRIO:\n\n\t\t\t\t\t\t\t");
	imprimirPilha(refeicao);
	printf("\n");
}

void moverChapeiro(int chapeiro[], char mapa[LIN][COL], int pontos, double tempo, struct fila *ordem_pedido, struct pilha *refeicao){	//função para mover o personagem
	char operador;
        int teste[2];
        teste[0] = chapeiro[0];
	teste[1] = chapeiro[1];

	operador = getchar();
	//andando para cima
	if(operador == 'w' && mapa[chapeiro[0]-1][chapeiro[1]] == ' ')
			chapeiro[0]--;
	//para baixo
	else if(operador == 's' && mapa[chapeiro[0]+1][chapeiro[1]] == ' ')
			chapeiro[0]++;
	//para a esquerda
	else if(operador == 'a' && mapa[chapeiro[0]][chapeiro[1]-1] == ' ')
			chapeiro[1]--;
	//para a direita
	else if(operador == 'd' && mapa[chapeiro[0]][chapeiro[1]+1] == ' ')
			chapeiro[1]++;
	imprimirMapa(mapa, chapeiro, pontos, tempo, ordem_pedido, refeicao);
}

int interacao(int chapeiro[], char mapa[LIN][COL]){		//função para interagir com as estações
	char interacao;
	if(mapa[chapeiro[0]+1][chapeiro[1]] == 'p'){
		scanf("%c", &interacao);
			return 1;
	}

	else if(mapa[chapeiro[0]+1][chapeiro[1]] == 'H'){
		scanf("%c", &interacao);
			return 2;
	}

	else if(mapa[chapeiro[0]+1][chapeiro[1]] == 'Q'){
		scanf("%c", &interacao);
			return 3;
	}

	else if(mapa[chapeiro[0]+1][chapeiro[1]] == 'S'){
		scanf("%c", &interacao);
			return 4;
	}

	else if(mapa[chapeiro[0]+1][chapeiro[1]] == 'P'){
		scanf("%c", &interacao);
			return 5;
	}

	else if(mapa[chapeiro[0]][chapeiro[1]-1] == ']' && mapa[chapeiro[0]][chapeiro[1]-2] == 'F'){
		scanf("%c", &interacao);
			return 6;
	}

	else if(mapa[chapeiro[0]][chapeiro[1]-1] == ']' && mapa[chapeiro[0]][chapeiro[1]-2] == 'R'){
		scanf("%c", &interacao);
		return 7;
	}

	else if(mapa[chapeiro[0]-1][chapeiro[1]] == 'o' || mapa[chapeiro[0]+1][chapeiro[1]] == 'o' || mapa[chapeiro[0]][chapeiro[1]-1] == 'o' || mapa[chapeiro[0]][chapeiro[1]+1] == 'o'){
		scanf("%c", &interacao);
			return 8;
	}
	else if(mapa[chapeiro[0]-1][chapeiro[1]] == '@'){
		scanf("%c", &interacao);
			return 9;
	}
	else if(mapa[chapeiro[0]-1][chapeiro[1]] == 'x' || mapa[chapeiro[0]+1][chapeiro[1]] == 'x' || mapa[chapeiro[0]][chapeiro[1]-1] == 'x' || mapa[chapeiro[0]][chapeiro[1]+1] == 'x'){
		scanf("%c", &interacao);
			return 10;
	}
	return 0;
}

void fim(int x){		//fim do jogo
	system("clear");
	for(int i = 0; i <= 20; i++)
		printf("\n");
	if(x > 0){
		Bgreen();
		printf("\t\t\t\t\t\t\tO   O  oOo  O   O     O   O OOOOO O   O\n");
		printf("\t\t\t\t\t\t\t O O  O   O O   O     O   O   O   OO  O\n");
		printf("\t\t\t\t\t\t\t  O   O   O O   O     O   O   O   O O O\n");
		printf("\t\t\t\t\t\t\t  O   O   O O   O     O O O   O   O  OO\n");
		printf("\t\t\t\t\t\t\t  O    OoO   OoO       O O  OOOOO O   O\n");
		reset();
	}
	else{
		Bred();
		printf("\t\t\t\t\t\t\t OOo   oOo  O   O OOOOO      oOo  O   O OOOOO OOOo\n");
		printf("\t\t\t\t\t\t\tO     O   O OO OO O         O   O O   O O     O   O\n");
		printf("\t\t\t\t\t\t\tO oOO OoooO O O O OOOO      O   O O   O OOOO  OOO°\n");
		printf("\t\t\t\t\t\t\tO   o O   O O   O O         O   O  O O  O     O  O\n");
		printf("\t\t\t\t\t\t\t OO°  O   O O   O OOOOO      OoO    O   OOOOO O   O\n");	
	}
	for(int i = 0; i <= 20; i++)
		printf("\n");
}

void darFree(struct fila *ordem_pedidos, struct pilha *refeicao){
	struct clientes *auxc = ordem_pedidos->inicio->prox;
	while(auxc){
		free(ordem_pedidos->inicio);
		ordem_pedidos->inicio = auxc;
		auxc = auxc->prox;
	}
	free(ordem_pedidos);
	struct pedido *auxp = refeicao->cabeca->prox;
	while(auxp){
		free(refeicao->cabeca);
		refeicao->cabeca = auxp;
		auxp = auxp->prox;
	}
	free(refeicao);
}
