#include <stdio.h>

void* burlando() {
    unsigned long int testando;
    testando = 5;
    return ((void*) &testando);
}

void main() {
    void *endereco = burlando();
    printf("%lu\n", *((unsigned long int*) endereco));
    return 0;
}