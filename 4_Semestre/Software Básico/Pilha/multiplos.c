#include <stdio.h>

long int v = 10;
long int t = 5;

long int multiplos() {
    long int m = 1;
    for (long int i = 2; i <= t; i++)
        if (v % i == 0)
            m += 1;
    return m;
}

int main() {
    return multiplos();
}