#include <stdio.h>

int copiar(int vetor[], int u[], int a, int b){
	int i = 0;
	while(i<=b-a){
		vetor[a+i] = u[i];
		i++;
	}
	return 0;
}

int merge(int vetor[], int a, int m, int b){
	if(a >= b)
		return 0;
	int k = 0;
	int i = a;
	int j = m+1;
	int p;
	int u[b-a+1];
	while(k <= b - a){
		if(j > b || (i <= m && vetor[i] <= vetor[j])){
			p = i;
			i++;
		}
		else{
			p = j;
			j++;
		}
		u[k] = vetor[p];
		k++;
	}
	return copiar(vetor, u, a, b);
}

int main(){
	int N;
	printf("Tamanho do vetor: ");
	scanf("%d", &N);
	int vetor[N];
	int a = 1;
	int m = N/2;
	for(int i = a; i<=N; i++){
		printf("vetor[%d] = ", i);
		scanf("%d", &vetor[i]);
	}
	merge(vetor, a, m, N);
	for(int j = a; j<= N; j++)
		printf("%d\t", vetor[j]);
	return 0;
}
