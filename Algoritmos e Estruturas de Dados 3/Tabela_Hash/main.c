#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main(){
	imprimirDadosAlunos();

    size_t tamTabela;
    scanf("%ld", &tamTabela);
    while (tamTabela <= 0 || sizeof(tamTabela) == sizeof(char)) {
        printf("Tamanho da tabela inválido.\n");
        getchar();
        scanf("%ld", &tamTabela);
    }

    struct nodoHash** tabelaHash;
    tabelaHash = gerarTabelaHash(tamTabela);

    int val;
    unsigned char entrada = 'x';

    while (entrada != 'f') {
        getchar();
        scanf("%c", &entrada);
        switch(entrada) {
            case 'i':
                scanf("%d", &val);
                if (!inserir(tabelaHash, tamTabela, val))
                    printf("Falha ao inserir %d.\n", val);
                break;
            case 'r':
                scanf("%d", &val);
                struct nodoHash* remover = buscar(tabelaHash, tamTabela, val);
                if (!remover)
                    printf("Falha ao remover %d.\n", val);
                else
                     excluir(tabelaHash, tamTabela, remover);
                break;
            case 'b':
                scanf("%d", &val);
                if (buscar(tabelaHash, tamTabela, val))
                    printf("Encontrado %d.\n", val);
                else
                    printf("Nao encontrado %d.\n", val);
                break;
            case 'l':
                imprimirTabelaHash(tabelaHash, tamTabela);
                break;
            case 'f':
                liberarTabelaHash(tabelaHash, tamTabela);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }        
    }
    return 0;
}
