#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 1000 //Defina o tamanho do seu buffer aqui

int main(void) {

  FILE *f = fopen("./teste.in", "w+");
  char *str;
  str = "SB\nMUITOSEGURO\nABCDEFGHIJKLMNOPQRSTUVWXA BANDEIRA É MINHA!\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\xa8\x51\x55\x55\x55\x55\n\n";
  fwrite(str, 1, STR_SIZE, f);  
  fclose(f);

  system("sudo sh -c 'echo 0 > /proc/sys/kernel/randomize_va_space'");
  system("./ctc < teste.in");
  system("sudo sh -c 'echo 2 > /proc/sys/kernel/randomize_va_space'");
}