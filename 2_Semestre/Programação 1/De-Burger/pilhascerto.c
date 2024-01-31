#include <stdio.h>
#include <stdlib.h>
#include "filacerto.h"
#include "structs.h"


void push (char ing,struct pilha *meal) {
    struct pedido *novo_noh;
    novo_noh = malloc (sizeof(struct pedido));
    if (novo_noh == NULL){
        printf("\nalocou errado ai");
    }
    if (meal->cabeca!=NULL){
        struct pedido *AJUDA;
        AJUDA = malloc (sizeof(struct pedido));
        AJUDA = meal->cabeca;
        novo_noh->ingrediente = ing;
        novo_noh->prox = meal->cabeca;
        meal->cabeca = novo_noh; 
        meal->cabeca->prox = AJUDA;
    }
    else {
        novo_noh->ingrediente = ing;
        novo_noh->prox = meal->cabeca;
        meal->cabeca = novo_noh;
    }
}

void deletarSanduiche (struct pilha *meall){
    struct pedido *aux;
    aux = meall->cabeca;
    while (aux){
        aux = meall->cabeca->prox;
        free (meall->cabeca);
        meall->cabeca = aux;
    }
}

void checkXburg (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado){
    struct pedido *ingredi;
    ingredi = meal->cabeca;
    if (ingredi->ingrediente == 'P'){
        ingredi=ingredi->prox;
        if (ingredi->ingrediente == 'Q'){
            ingredi=ingredi->prox;
            if (ingredi->ingrediente == 'H'){
                ingredi=ingredi->prox;
                if (ingredi->ingrediente == 'p'){
                    printf ("Hmmm era isso mesmo que eu queria!");
                    deletarSanduiche(meal);
                    *ptr_ponto = *ptr_ponto + 1;
                    pop_fila(fila_pedido);
                }
                else {
                    printf ("\n GGRRR não é o que eu pedi!");
                    deletarSanduiche(meal);
                    *ptr_ponto = *ptr_ponto - 1;
                    pop_fila(fila_pedido);
                    *ptr_errado = *ptr_errado+1;
                }
            }
            else {
                printf ("\n GGRRR não é o que eu pedi!");
                deletarSanduiche(meal);
                *ptr_ponto = *ptr_ponto - 1;
                pop_fila(fila_pedido);
                *ptr_errado = *ptr_errado+1;
            }
        }
        else {
             printf ("\n GGRRR não é o que eu pedi!");
             deletarSanduiche(meal);
             *ptr_ponto = *ptr_ponto - 1;
             pop_fila(fila_pedido);
             *ptr_errado = *ptr_errado+1;
        }
    }
    else {
        printf ("\n GGRRR não é o que eu pedi!");
        deletarSanduiche(meal);
        *ptr_ponto = *ptr_ponto - 1;
        pop_fila(fila_pedido);
        *ptr_errado = *ptr_errado+1;
    }
}

void checkXsal (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado){
    struct pedido *ingredi;
    ingredi = meal->cabeca;
    if (ingredi->ingrediente == 'P'){
        ingredi=ingredi->prox;
        if (ingredi->ingrediente == 'S'){
            ingredi=ingredi->prox;
            if (ingredi->ingrediente == 'H'){
                ingredi=ingredi->prox;
                if (ingredi->ingrediente == 'p'){
                    printf ("Hmmm era isso mesmo que eu queria!");
                    deletarSanduiche(meal);
                    *ptr_ponto = *ptr_ponto + 1;
                    pop_fila(fila_pedido);
                }
                else {
                    printf ("\n GGRRR não é o que eu pedi!");
                    deletarSanduiche(meal);
                    *ptr_ponto = *ptr_ponto - 1;
                    pop_fila(fila_pedido);
                    *ptr_errado = *ptr_errado+1;
                }
            }
            else {
                printf ("\n GGRRR não é o que eu pedi!");
                deletarSanduiche(meal);
                *ptr_ponto = *ptr_ponto - 1;
                pop_fila(fila_pedido);
                *ptr_errado = *ptr_errado+1;
            }
        }
        else {
             printf ("\n GGRRR não é o que eu pedi!");
             deletarSanduiche(meal);
             *ptr_ponto = *ptr_ponto - 1;
             pop_fila(fila_pedido);
             *ptr_errado = *ptr_errado+1;
        }
    }
    else {
        printf ("\n GGRRR não é o que eu pedi!");
        deletarSanduiche(meal);
        *ptr_ponto = *ptr_ponto - 1;
        pop_fila(fila_pedido);
        *ptr_errado = *ptr_errado+1;
    }
}

void checkCombo1 (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado){
    struct pedido *ingredi;
    ingredi = meal->cabeca;
    if (ingredi->ingrediente == 'R'){
        ingredi=ingredi->prox;
        if (ingredi->ingrediente == 'F'){
            ingredi=ingredi->prox;
            if (ingredi->ingrediente == 'P'){
                ingredi=ingredi->prox;
                if (ingredi->ingrediente == 'Q'){
                    ingredi=ingredi->prox;
                    if (ingredi->ingrediente == 'H'){
                        ingredi=ingredi->prox;
                        if (ingredi->ingrediente == 'p'){
                            printf ("Hmmm era isso mesmo que eu queria!");
                            deletarSanduiche(meal);
                            *ptr_ponto = *ptr_ponto + 1;
                            pop_fila(fila_pedido);
                        }
                        else {
                            printf ("\n GGRRR não é o que eu pedi!");
                            deletarSanduiche(meal);
                            *ptr_ponto = *ptr_ponto - 1;
                            pop_fila(fila_pedido);
                            *ptr_errado = *ptr_errado+1;
                        }
                    }
                    else {
                        printf ("\n GGRRR não é o que eu pedi!");
                        deletarSanduiche(meal);
                        *ptr_ponto = *ptr_ponto - 1;
                        pop_fila(fila_pedido);
                        *ptr_errado = *ptr_errado+1;
                    }
                }
                else {
                    printf ("\n GGRRR não é o que eu pedi!");
                    deletarSanduiche(meal);
                    *ptr_ponto = *ptr_ponto - 1;
                    pop_fila(fila_pedido);
                    *ptr_errado = *ptr_errado+1;
                }
            }
            else {
                printf ("\n GGRRR não é o que eu pedi!");
                deletarSanduiche(meal);
                *ptr_ponto = *ptr_ponto - 1;
                pop_fila(fila_pedido);
                *ptr_errado = *ptr_errado+1;
            }
        }
        else {
             printf ("\n GGRRR não é o que eu pedi!");
             deletarSanduiche(meal);
             *ptr_ponto = *ptr_ponto - 1;
             pop_fila(fila_pedido);
             *ptr_errado = *ptr_errado+1;
        }
    }
    else {
        printf ("\n GGRRR não é o que eu pedi!");
        deletarSanduiche(meal);
        *ptr_ponto = *ptr_ponto - 1;
        pop_fila(fila_pedido);
        *ptr_errado = *ptr_errado+1;
    }
}

void checkCombo2 (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado){
    struct pedido *ingredi;
    ingredi = meal->cabeca;
    if (ingredi->ingrediente == 'R'){
        ingredi=ingredi->prox;
        if (ingredi->ingrediente == 'F'){
            ingredi=ingredi->prox;
            if (ingredi->ingrediente == 'P'){
                ingredi=ingredi->prox;
                if (ingredi->ingrediente == 'S'){
                    ingredi=ingredi->prox;
                    if (ingredi->ingrediente == 'H'){
                        ingredi=ingredi->prox;
                        if (ingredi->ingrediente == 'p'){
                            printf ("Hmmm era isso mesmo que eu queria!");
                            deletarSanduiche(meal);
                            *ptr_ponto = *ptr_ponto + 1;
                            pop_fila(fila_pedido);
                        }
                        else {
                            printf ("\n GGRRR não é o que eu pedi!");
                            deletarSanduiche(meal);
                            *ptr_ponto = *ptr_ponto - 1;
                            pop_fila(fila_pedido);
                            *ptr_errado = *ptr_errado+1;
                        }
                    }
                    else {
                        printf ("\n GGRRR não é o que eu pedi!");
                        deletarSanduiche(meal);
                        *ptr_ponto = *ptr_ponto - 1;
                        pop_fila(fila_pedido);
                        *ptr_errado = *ptr_errado+1;
                    }
                }
                else {
                    printf ("\n GGRRR não é o que eu pedi!");
                    deletarSanduiche(meal);
                    *ptr_ponto = *ptr_ponto - 1;
                    pop_fila(fila_pedido);
                    *ptr_errado = *ptr_errado+1;
                }
            }
            else {
                printf ("\n GGRRR não é o que eu pedi!");
                deletarSanduiche(meal);
                *ptr_ponto = *ptr_ponto - 1;
                pop_fila(fila_pedido);
                *ptr_errado = *ptr_errado+1;
            }
        }
        else {
             printf ("\n GGRRR não é o que eu pedi!");
             deletarSanduiche(meal);
             *ptr_ponto = *ptr_ponto - 1;
             pop_fila(fila_pedido);
             *ptr_errado = *ptr_errado+1;
        }
    }
    else {
        printf ("\n GGRRR não é o que eu pedi!");
        deletarSanduiche(meal);
        *ptr_ponto = *ptr_ponto - 1;
        pop_fila(fila_pedido);
        *ptr_errado = *ptr_errado+1;
    }
}

void checkVegetariano (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado){
    struct pedido *ingredi;
    ingredi = meal->cabeca;
    if (ingredi->ingrediente == 'R'){
        ingredi=ingredi->prox;
        if (ingredi->ingrediente == 'F'){
            ingredi=ingredi->prox;
            if (ingredi->ingrediente == 'P'){
                ingredi=ingredi->prox;
                if (ingredi->ingrediente == 'Q'){
                    ingredi=ingredi->prox;
                    if (ingredi->ingrediente == 'p'){
                         printf ("Hmmm era isso mesmo que eu queria!");
                         deletarSanduiche(meal);
                         *ptr_ponto = *ptr_ponto + 1;
                         pop_fila(fila_pedido);
                    }
                    else {
                        printf ("\n GGRRR não é o que eu pedi!");
                        deletarSanduiche(meal);
                        *ptr_ponto = *ptr_ponto - 1;
                        pop_fila(fila_pedido);
                        *ptr_errado = *ptr_errado+1;
                    }
                    }
                else {
                    printf ("\n GGRRR não é o que eu pedi!");
                    deletarSanduiche(meal);
                    *ptr_ponto = *ptr_ponto - 1;
                    pop_fila(fila_pedido);
                    *ptr_errado = *ptr_errado+1;
                }
            }
            else {
                printf ("\n GGRRR não é o que eu pedi!");
                deletarSanduiche(meal);
                *ptr_ponto = *ptr_ponto - 1;
                pop_fila(fila_pedido);
                *ptr_errado = *ptr_errado+1;
            }
        }
        else {
            printf ("\n GGRRR não é o que eu pedi!");
            deletarSanduiche(meal);
            *ptr_ponto = *ptr_ponto - 1;
            pop_fila(fila_pedido);
            *ptr_errado = *ptr_errado+1;
        }
    }
    else {
        printf ("\n GGRRR não é o que eu pedi!");
        deletarSanduiche(meal);
        *ptr_ponto = *ptr_ponto - 1;
        pop_fila(fila_pedido);
        *ptr_errado = *ptr_errado+1;
    }
}

void checkVegano (struct pilha *meal, struct fila *fila_pedido, int *ptr_ponto, int *ptr_errado){
    struct pedido *ingredi;
    ingredi = meal->cabeca;
    if (ingredi->ingrediente == 'R'){
        ingredi=ingredi->prox;
        if (ingredi->ingrediente == 'F'){
            ingredi=ingredi->prox;
            if (ingredi->ingrediente == 'S'){
                printf ("Hmmm era isso mesmo que eu queria!");
                deletarSanduiche(meal);
                *ptr_ponto = *ptr_ponto + 1;
                pop_fila(fila_pedido);
            }
            else {
                printf ("\n GGRRR não é o que eu pedi!");
                deletarSanduiche(meal);
                *ptr_ponto = *ptr_ponto - 1;
                pop_fila(fila_pedido);
                *ptr_errado = *ptr_errado+1;
            }
        }
        else {
             printf ("\n GGRRR não é o que eu pedi!");
             deletarSanduiche(meal);
             *ptr_ponto = *ptr_ponto - 1;
             pop_fila(fila_pedido);
             *ptr_errado = *ptr_errado+1;
        }
    }
    else {
        printf ("\n GGRRR não é o que eu pedi!");
        deletarSanduiche(meal);
        *ptr_ponto = *ptr_ponto - 1;
        pop_fila(fila_pedido);
        *ptr_errado = *ptr_errado+1;
    }
}

void verificaentrega (int pedido, struct pilha *mmeal,struct fila *fila_pedidos, int *ptr_ponto, int *ptr_errado){
    if (pedido == 1){ //Xburguer
        checkXburg(mmeal,fila_pedidos, &*ptr_ponto,&*ptr_errado);
    }
    else if (pedido == 2){ // Xsal
        checkXsal(mmeal,fila_pedidos,&*ptr_ponto,&*ptr_errado);
    }
    else if (pedido == 3){ //Combo1
        checkCombo1(mmeal,fila_pedidos,&*ptr_ponto,&*ptr_errado);
    }
    else if (pedido == 4){ //Combo2
        checkCombo2 (mmeal,fila_pedidos,&*ptr_ponto,&*ptr_errado);
    }
    else if (pedido == 5){  //Combo3
        checkVegetariano(mmeal,fila_pedidos,&*ptr_ponto,&*ptr_errado);
    }
    else if (pedido == 6){  //Combo4
        checkVegano(mmeal,fila_pedidos,&*ptr_ponto, &*ptr_errado);
    }
}

void poppilha(struct pilha *refeicao){
    struct pedido *aux;
    aux = refeicao->cabeca;
    if (aux){
        refeicao->cabeca = aux->prox;
        aux->prox = NULL;
        free(aux);
    }
}

void definirRefeicao (int interacacao, struct pilha *mmeal, int pedido, struct fila *ordem_pedido, int *ptr_ponto, int *ptr_errado, int *ptr_lixo){
    if (interacacao == 1){
        push ('p',&*mmeal);
    } 
    else if (interacacao == 2){
        push ('H',&*mmeal);
    }
    else if (interacacao == 3){
        push ('Q',&*mmeal);
    }
    else if (interacacao == 4){
        push ('S',&*mmeal);
    }
    else if (interacacao == 5){
        push ('P',&*mmeal);
    }
    else if (interacacao == 6){
        push ('F',&*mmeal);
    }
    else if (interacacao == 7){
        push ('R',&*mmeal);
    }
    else if (interacacao == 8){
        printf ("\n\t\t\tAah, fiz errado :(\n");
        deletarSanduiche(mmeal);
        *ptr_lixo = *ptr_lixo + 1;
    }
    else if (interacacao == 9){
        if (mmeal->cabeca){
            verificaentrega(pedido,mmeal,ordem_pedido, &*ptr_ponto, &*ptr_errado);
        }
        else{
            printf("... mas não tem nada aí.\n");
            *ptr_ponto = *ptr_ponto -1;
            pop_fila(ordem_pedido);
        }
    }
    else if (interacacao ==10){
        poppilha(mmeal);
    }
}



void imprimirPilha(struct pilha *refeicao){
    struct pedido *aux;
    aux = refeicao->cabeca;
    while(aux){
        printf ("[%c] ", aux->ingrediente);
        aux = aux->prox;
    }
}

