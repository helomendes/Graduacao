# Otimização de Código Serial

O trabalho apresentado visa otimizar e melhorar a performance de funções de
multiplicação de matrizes. 

## Autoras

- Gabriela Fanaia de Almeida Dias Dorst, GRR 20220070
- Heloisa Benedet Mendes, GRR 20221248

## Execução

Para compilar e executar os arquivos corretamente, use o comando:

        ./script.sh

## Contexto

A análise de desempenho das funções foi realizada através de uma série de
testes com os seguintes parâmetros:

### Métricas Analisadas

- Tempo de Execução
- Banda de Memória
- Cache Miss L2
- Energia
- Operações Aritméticas

### Dimensões

Cada métrica foi observada para diferentes dimensões de matrizes:
64, 100, 128,  200, 256, 512, 600, 900, 1024, 2000, 2048, 3000, 4000, 5000, 6000, 10000

## Otimizaçaões feitas

### Alocação de Memória

Para otimizar a alocação de memória, foi inserido um padding de 64 bytes
para evitar cache thrashing. Esse valor pode variar conforme a arquitetura,
pois depende do tamanho da linha de cache. Assim, ao alocar memória para os
vetores, adiciona-se 64 bytes à sua dimensão inferior.

### MatVet

Esta função realiza a multiplicação de matriz por vetor empregando a técnica
de Unroll & Jam com um fator de 8. Esse valor foi escolhido após a realização
de testes com diversos fatores.

### MatMat

Para otimizar a multiplicação de matrizes, foram aplicadas as técnicas de
Unroll & Jam com fator 8 e Blocking com fator 32. Esses valores foram selecionados
após uma avaliação de diferentes alternativas para maximizar o desempenho.

Foi implementado um tratamento para os elementos restantes ao final da função.
Inicialmente, foram processadas as colunas remanescentes até o final da linha
do bloco final. Em seguida, foram tratadas as linhas que não foram cobertas 
pelos blocos.

## Resultados

Analisando os resultados dos testes, observamos uma melhora significativa no tempo
de execução e na eficiência energética da multiplicação de matrizes.
Consequentemente, essa função apresentou os melhores resultados em termos de
Operações Aritméticas FLOPS_DP. No entanto, apesar da utilização de vetorização,
não foram observadas Operações Aritméticas FLOPS_AVX. Em termos de desempenho
de memória, a função demonstrou melhorias na taxa de Cache Miss L2, mas sua
performance diminuiu significativamente sua largura de banda quando comparada à
sua versão não otimizada.

De maneira similar, a função de multiplicação de matriz por vetor apresentou
melhor desempenho no tempo de execução, no gasto energético e nas Operações
Aritméticas FLOPS_DP. Esta foi a única função a demonstrar Operações Aritméticas
FLOPS_AVX, resultado da vetorização aplicada. Além disso, a largura de banda
da função foi consistentemente superior em comparação com as outras funções
testadas. A taxa de cache miss, no entando, aumentou significativamente sem uma
causa aparente. As possíveis causas desse aumento são:

- Overhead de memória causado pelo padding excessivo
- Acessos de memória não sequenciais por Unroll & Jam mal projetado
- Overhead de gerenciamento e manipulação dos blocos de dados
- Tamanho do bloco mal calibrado, mal aproveitamento de dados

A aplicação inadequada ou escolhas não ótimas para as técnicas de otimização
podem motivar o aumento observado na taxa de cache miss da multiplicação de
matrizes por vetores.

## Arquivos

### filter.py

Programa para filtrar a análise do LIKWID com base na métrica específica
estudada.

### matmult.c

Este código executa funções com e sem otimização, utilizando o LIKWID para
aplicar as marcações necessárias.

Funções de alocação de memória e operações de multiplicação de matrizes
e vetores sem o uso de otimização.

### matriz_otimizada.c -> funções otimizadas

Aplicação de técnicas de otimização nas funções de alocação de memória
e operações de multiplicação de matrizes e vetores, definidas no arquivo
'matriz.c'.

### plot.py -> colocar arquivos dos graficos

Plotagem de gráficos das métricas analisadas com base nos resultados gerados
pelo arquivo 'script.sh'.

### plot_time.py

Plotagem de gráfico exclusiva da métrica Tempo de Execução, também se
baseia nos resultados fornecidos por 'script.sh'.

### script.sh

Script shell para executar o pipeline:
Execução Funções -> Análise LIKWID -> Filtragem -> Plotagem de Gráfico
Abrangendo todas as métricas e dimensões estipuladas.
