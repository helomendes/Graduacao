### Comandos

Ativar ambiente virtual:

> source .cripto/bin/activate

Executar script:

> python3 main.py

Executar criptografia:

> Uso: python3 criptografar.py arquivo chave trilhos

> Exemplo: python3 criptografar.py texto.txt SEGREDO 3

Executar descriptografia

> Exemplo: python3 descriptografar.py criptografo.txt SEGREDO 3



### Organzação do trabalho

- [x]  Implementação do AES
- [x]  Implementação do código de criptografar (playfair e rail fence)
- [x]  Implementação do código de descriptografar
- [x]  Implementação do Código da leitura dos arquivos(usar chunks) e ajustar com a criptografia e descriptografia.
- No Playfair, guardar a última letra de um bloco se não fechou um par, para usar no próximo bloco.
- No Rail Fence, escrever as letras diretamente em "buffers" de cada trilho conforme percorre o arquivo -> não precisa ter tudo em memória
- [ ]  Testar com arquivo de tamanhos diferentes(pequeno, médio grande)
- [ ]  Adicionar medição de tempo para fazer comparação com AES e fazer relatório

# Fluxo

## Criptografar.py

### Gerar matriz Playfair (7x5)
- Remove duplicatas da chave.

- Adiciona todas as letras do alfabeto que não estão na chave.

- Adiciona os caracteres extras (EXTRA\_CHARS) que não estão na chave nem no alfabeto.

- Divide em 7 linhas de 5 colunas (7x5 = 35 posições).

### Preparar texto Playfair
- Converte tudo para maiúsculo.

- Remove caracteres inválidos. (não estão na matriz)

- Cria pares de caracteres: Se dois caracteres consecutivos forem iguais, adiciona um ‘X’ como padding.

- Se o texto tiver número ímpar de caracteres, adiciona ‘X’ no final.

### Localizar posição na matriz
- Percorre a matriz para encontrar a linha e coluna de um caractere.

- Se não encontrar, lança erro (útil para detectar caracteres não suportados).

### Cifrar texto com Playfair

- Mesmo linha: move cada letra 1 coluna à direita (circular).

- Mesmo coluna: move cada letra 1 linha para baixo (circular).

- Retângulo: troca colunas das letras.

### Cifra Rail Fence
- Distribui letras em uma espécie de zig-zag pelos trilhos.

- Depois junta todas as linhas.

### Processamento em chunks
- Lê o arquivo em blocos de tamanho chunk\_size para não sobrecarregar a memória.

- Limpa caracteres inválidos.

- Se houver um caractere sobrando, guarda em resto para o próximo chunk.

- Aplica Playfair no chunk.

- Aplica Rail Fence no resultado do chunk.

- Junta todos os trilhos no final.

## Descriptografar.py

### Decifrar Rail Fence

- Cria padrão de trilhos (rail\_pattern) para saber a posição de cada letra no zig-zag.

- Distribui os caracteres do texto cifrado nos trilhos correspondentes.

- Reconstrói o texto original seguindo o padrão de zig-zag.

- Retorna o texto antes de Playfair, mas ainda cifrado com Playfair.

### Decifrar Playfair
- Gera a matriz Playfair (mesmo que na cifragem) com 7 linhas × 5 colunas.

- Percorre o texto em pares de caracteres.

- Aplica regras inversas da Playfair:

- Mesma linha: move 1 coluna para esquerda (circular).

- Mesma coluna: move 1 linha para cima (circular).

- Retângulo: troca colunas do par.

- Retorna o texto decifrado com padding ‘X’ ainda presente.

### Remover X adicionados como padding

- A função não remove todos os X, apenas os que foram inseridos como padding ou para separar letras iguais.

- Último X adicionado apenas para completar pares também é removido.

- O texto retornado é uma aproximação fiel do original antes da cifragem.
