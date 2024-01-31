#include <stdio.h>

int mccarthy(int n){
	if (n > 100){
		printf("%d\t", n-10);
		return n-10;
	}
	printf("%d\t", n+11);
	return mccarthy(mccarthy(n+11));
}

int main(){
	int n;
	printf("n: ");
	scanf("%d", &n);
	printf("%d\n", mccarthy(n));
	return 0;
}
