#include <stdio.h>

void red () {
  printf("\033[0;31m");
}


void yellow () {
  printf("\033[0;33m");
}


void green (){
    printf("\033[0;32m");
}


void blue(){
    printf ("\033[0;34m");
}


void black(){
    printf ("\033[0;30m");
}

void Bred () {
  printf("\033[1;31m");
}


void Byellow () {
  printf("\033[1;33m");
}


void Bgreen (){
    printf("\033[1;32m");
}


void Bblue(){
    printf ("\033[1;34m");
}


void Bblack(){
    printf ("\033[1;30m");
}

void Bwhite () {
  printf("\033[1m");
}

void reset () {
  printf("\033[0m");
}

void purple(){
    printf("\033[0;35m");
}


void cyan(){
    printf("\033[0;36m");
}

void Bpurple(){
    printf("\033[1;35m");
}


void Bcyan(){
    printf("\033[1;36m");
}


void brightred(){
  printf ("\033[1;91m");
}

void brightyellow(){
  printf ("\033[1;93m");
}

void brightgreen(){
  printf ("\033[1;92m");
}

void brightblue(){
  printf ("\033[1;94m");
}

void brightblack(){
  printf ("\033[1;90m");
}

void brightpurple(){
  printf ("\033[1;95m");
}

void brightcyan(){
  printf ("\033[1;96m");
}

void blck(){
  printf("\e[0;100m");
}
void redb(){
  printf("\e[41m");
}
void grnb(){
  printf("\e[42m");
}
void yelb(){
  printf("\e[43m");
}
void blub(){
  printf("\e[44m");
}
void magb(){
  printf("\e[45m");
}
void cynb (){
  printf("\e[46m");
}
void whtb(){
  printf("\e[47m");
}


