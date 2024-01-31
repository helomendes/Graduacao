#include <stdio.h>

long int modulo(long int a) {
    if (a >= 0)
        return a;
    else
        return -a;
}

int main() {
    long int v = -10;
    return modulo(v);
}