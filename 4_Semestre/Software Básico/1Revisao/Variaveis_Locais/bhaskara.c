#include <stdio.h>

long int a = 4;
long int c = -1;

long int calculaDelta() {
    long int delta;
    delta = -4 * a * c;
    if (delta >= 0)
        return 1;
    return 0;
}

int main() {
    return calculaDelta();
}