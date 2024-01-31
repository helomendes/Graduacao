# Trabalho 2 - Tabelas Hash

Implementação de uma Tabela Hash com função hash estática em C.
A Tabela possui chaves inteiras e não aceita duplicatas, colisões são tratadas por meio de listas duplamente encadeadas.

## Índice

* [Estrutura]
* [Descrição]
* [Contato]

## Estrutura

O trabalho está dividido em 4 arquivos:
* makefile - Possui as intruções de compilação e os arquivos a serem compilados.
* main.c - Além de criar a Tabela Hash, obtém as entradas a partir da entrada padrão (stdin), que consistem em caracteres para definir a operação desejada (i inserir, r remover, b buscar, l imprimir, f finalizar) e, nos casos 'i', 'r' e 'b', são acompanhados de um valor inteiro. A primeira entrada deverá ser um número inteiro maior que zero, que deve definir o tamanho da Tabela Hash.
* tabelaHash.h - Headers das funções utilizadas e uma breve explicação de seus funcionamentos. Foi incluído ao Template original a função hash(int k, int m).
* tabelaHash.c - Implementação de cada função apresentada no arquivo tabelaHash.h a partir do Template fornecido.

## Descrição

* gerarTabelaHash - Cria e retorna a Tabela Hash, um vetor de ponteiros para structs do tipo nodoHash. Aloca espaço suficiente para a Tabela Hash na memória a partir do tamanho indicado por meio de "calloc", de forma que os elementos são inicializados com 0.

* liberarTabelaHash - Desaloca a memória, primeiramente índice a índice no vetor, seguindo as listas (quando existentes), para então desalocar a Tabela Hash. Retorna void.

* hash - Calcula o índice correto de determinada chave no vetor Tabela utilizando a função k mod m, onde k é a chave e m é o tamanho da Tabela. Trata resultados negativos de maneira a sempre retornar um inteiro positivo.

* buscar - Procura a chave desejada na Tabela por meio do cálculo do índice através da função hash, e, caso haja colisões, percorrendo a lista na posição obtida do vetor. Retorna o nodo que contém a chave, caso seja encontrado, ou NULL, caso contrário.

* inserir - Utiliza a função buscar para previnir duplicatas. Se a chave não se encontra na Tabela, ou seja, não é uma duplicata, é adicionada ao fim da lista no índice indicado pela função hash, o que inclui sua primeira posição,e retorna o nodo inserido. Se ela já existe, retorna NULL.

* excluir - Neste caso, a função de busca é usada ainda no main.c, para então, caso esta retorne um nodo, chamar a função excluir para ele, ou então imprimir erro. Excluir trata os 3 casos de exclusão: exclusão do primeiro item da lista, de um item que se encontra no meio dela, e do último elemento da lista. Retorna void.

* imprimir - Imprime na saída padrão a Tabela Hash completa, conforme o exemplo:
0 [0] -> [10] -> NULL
1 [1] -> NULL
2 NULL
Onde o tamanho da Tabela é 3, e possui os elementos 0, 1 e 10.

## Contato

* GitHub: [helomendes](https://github.com/helomendes)
* E-mail UFPR: heloisamendes@ufpr.br