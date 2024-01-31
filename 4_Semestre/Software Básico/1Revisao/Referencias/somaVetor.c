#include <stdio.h>

int soma_vetor(int vetor[], int tam) {
    int soma = vetor[0];
    for (int i = 1; i < tam; i++)
        soma += vetor[i];
    return soma;
}

int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return soma_vetor(vetor, 10);
}