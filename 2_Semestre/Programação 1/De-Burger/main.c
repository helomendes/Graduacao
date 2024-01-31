#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "mapa.h"
#include "pilhascerto.h"
#include "filacerto.h"
#include "structs.h"

#define LIN 10
#define COL 27

int main(){
	srand(time(NULL));
	char inter;
	int interaction;
	int pontos = 0;
	int *ptr_ponto;
	ptr_ponto = &pontos;

	int pedido = 0;
	int *ptr_pedido = &pedido;
	int qualpedido = 0;
    	int *numero_cliente;
    	numero_cliente = &qualpedido;

 	struct fila *ordem_pedido;
	ordem_pedido = malloc (sizeof(struct fila));
    	ordem_pedido->inicio=NULL;

    	struct pilha *refeicao;
    	refeicao = malloc (sizeof(struct pilha));
    	refeicao->cabeca = NULL;

	int errado=0;
	int *ptr_errado;
	ptr_errado = &errado;
	int lixo=0;
	int *ptr_lixo;
	ptr_lixo = &lixo;

	clock_t start, end;
	double tempo = 0;
	char mapa[LIN][COL];
	int chapeiro[2] = {LIN/2, COL/2};
	criarMapa(mapa);

	start = clock();
	headerSleep(15);
	imprimirMapa(mapa, chapeiro, pontos, 0, ordem_pedido, refeicao);	
	inicio();

	for(int x = 0; x < 5; x++)
		getPedido(ordem_pedido, &*numero_cliente);
	int x=0;
	int i=1;
	while(tempo*1000 <= 300){
		if (x==75*i){
			getPedido(ordem_pedido, &*numero_cliente);
			i=i+1;
		}
		checarpedido(&*ptr_pedido, ordem_pedido);
		moverChapeiro(chapeiro, mapa, pontos, tempo, ordem_pedido, refeicao);
		interaction = interacao(chapeiro, mapa);
		definirRefeicao (interaction,refeicao,pedido,ordem_pedido, &*ptr_ponto, &*ptr_errado,&*ptr_lixo);
		end = clock();
		x=x+1;
		tempo = ((double)end-start)/CLOCKS_PER_SEC;
		if(errado >= 3 || lixo >= 5){
			fim(0);
			darFree(ordem_pedido, refeicao);
			return 0;
		}
	}
	fim(pontos);
	darFree(ordem_pedido, refeicao);
	return 0;
}
