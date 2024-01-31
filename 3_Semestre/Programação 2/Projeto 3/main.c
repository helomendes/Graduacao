#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum { NOP, ENCODE, DECODE } Modo_t;

#define BUFFER_SIZE 10

// PROTÓTIPOS

// Função que comprime 'fIn', gravando o resultado da compressão em 'fOut'
void Encode (char* input, char* output);

// Função que descomprime 'fIn', gravando o resultado da descompressão em 'fOut'
void Decode (char* input, char* output);

// Função  ser  usada  no  programa para  chamar  Encode()  ou  Decode()
void rle (void (*func) (char*, char*), char* input, char* output);


// PROGRAMA PRINCIPAL
int main(int argc, char *argv[])
{

  int opt;
  char *input = NULL;
  char *output = NULL;
  Modo_t modo = NOP;
  
  while ((opt = getopt(argc, argv, "dei:o:")) != -1) {
    switch (opt) {
    case 'i':
      input = strdup(optarg);
      break;
    case 'o':
      output = strdup(optarg);
      break;
    case 'e':
      modo |= ENCODE;
      break;
    case 'd':
      modo |= DECODE;
      break;
    default:
      fprintf(stderr, "Forma de uso: ./rle [-e | -d] -i <arq_in> -o <arq_out>\n");
      exit(1);
    }		
  }

  // Erro se:
  //  * não forneceu os dois arquivos
  //  * não forneceu uma das opções '-e' ou '-d',
  //  * forneceu as opções '-e' e '-d' na mesma linha de comando
  if ( ! input || ! output || modo == NOP || modo & (modo-1) ) {
    fprintf(stderr, "Forma de uso: ./rle [-e | -d] -i <arq_in> -o <arq_out>\n");
    exit(2);
  }
  
  /* COMPLEMENTE O CÓDIGO PARA DESENVOLVER O PROGRAMA PRINCIPAL A PARTIR DESTE PONTO */
  if (modo == ENCODE)
	  rle(Encode, input, output);
  else
	  rle(Decode, input, output);

  return 0 ;

}


/* DEFINA ABAIXO O CÓDIGO DAS FUNÇÕES Encode(), Decode() e rle()  */

// Função ser usada no programa principal para chamar Encode() ou Decode()
void rle (void (*func) (char*, char*), char* input, char* output)
{
	func(input, output);
}



// Função que comprime 'fIn', gravando o resultado da compressão em 'fOut'
void Encode (char* input, char* output)
{
	FILE* original;
	FILE* comprimido;
	original = fopen(input, "r");
	comprimido = fopen(output, "w");

	if (!original || !comprimido) {
		perror("Falha ao abrir arquivo.");
		exit(1);
	}

	char ant;
	char atual;
	int contador = 1;

	ant = fgetc(original);
	int lidos = 1;

	while (!feof(original)) {
		atual = fgetc(original);
		if (atual == ant) { 
			contador++;
		} else {
			fprintf(comprimido, "%c%d", ant, contador);
			contador = 1;
		}
		ant = atual;
	}

	fclose(original);
	fclose(comprimido);
}



// Função que descomprime 'fIn', gravando o resultado da descompressão em 'fOut'
void Decode (char* input, char* output)
{
	FILE* comprimido;
	FILE* descomprimido;
	comprimido = fopen(input, "r");
	descomprimido = fopen(output, "w");

	if (!comprimido || !descomprimido) {
		perror("Falha ao abrir arquivo.");
		exit(1);
	}

	int it;
	char car;

	while (!feof(comprimido)) {
		car = fgetc(comprimido);
		it = fgetc(comprimido);
		it = it-48;
		while (it > 0) {
			fprintf(descomprimido, "%c", car);
			it--;
		}
	}

	fclose(comprimido);
	fclose(descomprimido);
}

