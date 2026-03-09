#include <stdio.h>

int multiplicacao(int n, int m){
	if (m == 0)
		return 0;
	if (m >= 1)
		return n + multiplicacao(n, m-1);
	return -n + multiplicacao(n, m+1);
}

int main(){
	int n, m;
	printf("n: ");
	scanf("%d", &n);
	printf("m: ");
	scanf("%d", &m);
	printf("%d\n", multiplicacao(n, m));
	return 0;
}
