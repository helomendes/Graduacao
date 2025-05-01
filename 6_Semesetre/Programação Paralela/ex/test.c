#include <stdio.h>

int main() {
int x;
scanf("%d", &x);

if(x > 0 && x < 10){
     printf("X eh maior que 0 e menor que 10.\n");
     if(x > 0)
          if((x%2)==0)
               printf("Numero positivo e par.");
          else
               printf("Numero positivo e impar.");
          else if((x%2)==0)
               printf("Numero negativo e par.");
          else
               printf("Numero negativo e impar.");}
     else if(x < 0 && x > -10)
          printf("X eh menor que 0 e maior que -10.\n");
	return 0;
}
