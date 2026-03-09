#include <stdio.h>
#include <string.h>

char N_LOGIN = 0;
char USER[] = "SB";
char PASS[] = "MUITOSEGURO";
char STD_SUCCESS[] = "OPERAÇÃO BEM SUCEDIDA!\n";

int main(void);

void acesso(){
  printf("%s\n", STD_SUCCESS);
}

void login(){
  unsigned long int protocolo = ((unsigned long int) acesso) - 1;
  char P_USER[15], P_PASS[15];

  printf("O SEU PROTOCOLO DE ACESSO É: %lu\n", protocolo);
  printf("Digite o seu LOGIN: \n");
  gets(P_USER);
  printf("Digite a sua SENHA: \n");
  gets(P_PASS);

  if ((!strncmp(P_USER, USER, 2)) && (!strncmp(P_PASS, PASS, 11))){
    if (!N_LOGIN){
      printf("PRIMEIRO LOGIN, TROQUE A SENHA: \n");
      gets(PASS);
    }
    N_LOGIN++;
    acesso();
  }
  else{
    printf("VOCÊ ERROU A SENHA!\n");
  }
}

int main(void) {
  for (int i = 0; i < 2; i++){
    login();
  }
}