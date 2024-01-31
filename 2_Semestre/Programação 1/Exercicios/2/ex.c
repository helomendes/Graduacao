#include <stdio.h>

int main(){
	int m = 10;
	int n;
	int o;
	int *z;
	z = &m;
	printf("a) Endereço de m: %p\n", z);
	printf("b) Valor armazenado em z: %p\n", z);
	printf("c) Valor armazenado no endereço apontado por z: %i\n", *z);
	z = &n;
	printf("d) Endereço de n: %p\n", z);
	z = &o;
	*z = m;
	printf("e) o recebe m, valor armazenado em o: %i\n", *z);
	printf("f) Endereço de z: %p\n", z);
	printf("g) Não dá\n");
	printf("h) Não dá\n");
	return 0;
}

