# Resolução de sistemas lineares, Eliminação de Gauss e Gauss-Seidel

O programa desenvolvido calcula as soluções de um sistema linear fornecido a partir de 4 métodos de resolução.

- Eliminação de Gauss
- Gauss-Seidel
- Eliminação de Gauss Tridiagonal
- Gauss-Seidel Tridiagonal

É mostrado na saída padrão o tempo levado por cada método (calculado a partir da biblioteca time.h), seus resultados, o resíduo gerado e as métricas calculadas pelo LIKWID.

## Autores 

- Gabriela Fanaia de Almeida Dias Dorst, GRR 20220070

- Heloisa Benedet Mendes, GRR 20221248

## Execução

Primeiramente, use o comando make para compilar os programas necessários e gerar o arquivo executável.

	make

Para executar o programa de forma padrão, rode o executável e use como entrada um arquivo .dat com o sistema linear A*X = B a ser solucionado, neste trabalho existe um arquivo exemplo sl.dat que pode ser utilizado.

	./perfSL < sl.dat

O arquivo .dat deve ter a seguinte formatação:

	n
	A00 A01 ... A0n X0 B0
	A10 A11 ... A1n X1 B1
	...
	An0 An1 ... Ann Xn Bn

Para executar o programa utilizando os marcadores do LIKWID, use o programa script.h.
 
	./script.sh

## Estrutura

O programa é modulado em diferentes bibliotecas e arquivos:

### main.c

É inicializado o marcador do LIKWID, bem como as estruturas de dados a serem utilizadas pelo programa.

O sistema linear então é resolvido de 4 formas diferentes:

Eliminação de Gauss

Método Gauss-Seidel

Eliminação de Gauss Tridiagonal

Método Gauss-Seidel Tridiagonal

E, por fim, encerra o marcador do LIKWID e desaloca as estruturas.

### toolbox.h

Ferramentas necessárias para a construção do programa.

Definição de macros de retorno para ambos os métodos (possível, impossível e indeterminado) e de limites exclusivamente para o método Gauss-Seidel (limite de iterações e tolerância de erro).

Funções para a aplicação dos métodos tradicionais e tridiagonais.

Alocação e desalocação de matrizes e vetores.

Leitura do sistema linear no arquivo .dat.

Impressão formatada na saída padrão de resíduo, incognitas e de tempo.

### structs.h

Foram criadas duas estruturas de dados para armazenar de forma simples o sistema linear a ser solucionado:

struct SL - para sistemas lineares padrões, os coeficientes são armazenados na matriz A, as incognitas no vetor x, os termos independentes no vetor b e a ordem do sistema em um int_t n.

struct tridiagonal - para sistemas lineares tridiagonais, cada uma das diagonais é armazenada em um dos vetores a, c ou d, enquanto o armazenamento das incognitas, termos independentes e ordem do 
sistema é equivalente ao anterior.

Além disso, esta biblioteca possui funções de inicialização, cópia, restauração e desalocação para ambas as estruturas.

### EG.h

Funções voltadas para a aplicação do método da Eliminação de Gauss padrão e tridiagonal.

Possui as funções de pivoteamento parcial e trocar linhas, além de retrosubstituição e cálculo de resíduo.
	
### GS.h

Funções para a aplicação do método Gauss-Seidel tradicional e tridiagonal.	

## Casos Especiais

Em determinados casos, o programa apresenta resultados incongruentes.

Alguns sistemas lineares tridiagonais geram resultados diferentes entre os métodos clássico e tridiagonal da Eliminação de Gauss, e também não convergem para os métodos de Gauss-Seidel.

	3
	1 4 52 57
	27 110 -3 134
	22 2 14 38

Este sistema obtém resultados próximos através dos métodos tridiagonais, mas que divergem da EG clássica. Além de não atingir a tolerância de erro em até 50 iterações no GS clássico.

	3
	1 0 3 3
	0 -1 1 1
	2 1 3 9
