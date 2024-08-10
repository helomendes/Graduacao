# Cifra de Beale
Projeto 2 da matéria de Programação 2.

#Índice

* Biblioteca(#biblioteca)
* Contato(#contato)

## Bibliotecas:

CHAVE:
Os arquivos .h e .c de nome "chave" tratam da criação do arquivo de chaves usado na criptografia.
Tem como função principal "arquivoDeChaves" e faz uso de uma lista encadeada de listas, sendo que a estrutura da lista encadeada possui as informações de char e de uma segunda lista para armazenar os seus codigos, com inserção ordenada - comparando sempre se o caractere é menor, igual, ou maior que o caractere inicial da lista, e, portanto, fazendo inserção na cabeça, na cauda e no meio das listas.
Para a extração dos codigos lê-se caractere por caractere, se o caractere imediatamente anterior for um espaço ' ' ou uma nova linha '\n', adiciona-se 1 ao contador de palavras e o caractere é incluido na lista juntamente com o contador atual (o número da palavra que ele inicia, ou seja, seu código).
Por fim, a escrita no arquivo .txt é feita pela função "escreverArquivo", que usa a lista encadeada para escrever de forma formatada.

CODIFICAR:
Esta biblioteca trata da codificação do texto, e, portanto, da funcionalidade -e.
Ela utiliza as funções da biblioteca "chave.h" para criar um arquivo de chaves a partir do livro cifra fornecido, com base nesse arquivo encontra os códigos de cada caractere.
Em primeiro lugar, verifica-se o caractere que pretende cifrar, depois, analisa se é um espaço ' ', ou não, caso sim, escreve "-1" no arquivo da mensagem codificada.
Caso não, o procura no arquivo de chaves, se não estiver listado, escreve um "*" no arquivo da codificação, representando um caractere desconhecido.
Se estiver listado, é criada uma lista com as posições ocupadas por este caractere, mantendo conta de quantas são essas posições para, após isso, randomizar um número k que pertença ao intervalo [0..a], sendo a o número de posições do caractere, e então escolher a k-ésima posição como código para a criptografia.

DECODIFICAR:
É usada a mesma função para ambas as funcionalidades de -d, portanto, os diferentes casos são separados por if's.
A decodificação usa uma lógica bastante semelhante à codificação, porém inversa. A função lê o código a ser decifrado, e procura no arquivo chave (fornecido ou criado a partir do livro cifra) este mesmo código.
Ao encontrar, volta ao começo da linha, até encontrar a que caractere o código pertence, e escreve este no arquivo de decodificação. Caso o código seja "-1", exatamente ao contrário da codificação, escreve-se um espaço ' ' no arquivo.

BEALE:
Utiliza as 3 bibliotecas citadas com base nos argumentos passados na chamada da função "beale".
Utiliza a flag 'e' para identificar as funções chamadas e definir o programa - se a flag_e for ativada, significa que foi solicitada a codificação de uma mensagem, se não, é necessária a decodificação, que, como explicado no paragrafo anterior, obedece aos parâmetros enviados.
Os parâmetros passados como argumentos na chamada da função são extraídos através do vetor argv e utilizadas para a criação e abertura dos arquivos desejados.

Os números encontrados nos arquivos são armazenados usando a seguinte lógica:
Enquanto o caractere lido não for um espaço ' ', ele é transformado em inteiro (caractere - 48, pela tabela ASCII), e somado à um número n * 10, sendo n inicialmente igual a 0. Quando o espaço é encontrado, o número é, ou, armazenado como código, ou, comparado com o código sendo buscado.
No caso de o número ser igual ao código necessário, significa que o ponteiro do arquivo está na linha do caractere correspondente, então, volta-se o ponteiro até encontrar o ':', e mais um byte para ler o caractere, que é armazenado no arquivo de mensagem decifrada.

## Contato:

* GitHub: [helomendes](https://github.com/helomendes)
* E-mail: heloisabmendes@gmail.com
