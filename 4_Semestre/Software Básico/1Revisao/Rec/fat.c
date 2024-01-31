#include <stdio.h>

unsigned long int fat(unsigned long int n) {
    if (n == 1)
        return 1;
    else
        return n*fat(n-1);
}

int main() {
    return fat(3);
}