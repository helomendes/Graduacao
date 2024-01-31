#include <stdio.h>

int calcular_area(int raio) {
    int A = (raio)*(raio);
    A = A * 3;
    return A;
}

int main() {
    int raio = 10;
    return calcular_area(raio);
}