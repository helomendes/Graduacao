#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int palindromo(int v[], int a, int b){
	if (a >= b)
		return 1;
	if (v[a] == v[b])
		return(palindromo(v, a+1, b-1));
	return 0;
}
void preencherAleatorio(int v[], int maxVal){
	int i;
	for(i = 0; i < TAM; i++)
		v[i] = rand()%maxVal;
}
void imprimeVetor(int v[]){
    for(int i=0; i < TAM; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main(){
	int v[TAM];
	int a = 0, b = TAM;
	int maxVal;
	printf("Insira o valor máximo do vetor: ");
	scanf("%d", &maxVal);
	preencherAleatorio(v, maxVal);
	imprimeVetor(v);
	if (palindromo(v,a,b) == 0)
		printf("Não é palíndromo.\n");
	else
		printf("É palíndromo.\n");
	return 0;
}
