#include <stdio.h>
#define N 4

int intercalar(int V[], int W[], int vetorIntercalado[])
{
	int i;
	for (i = N-1; i >= 0; i--)
		vetorIntercalado[i*2] = V[i];
	for (i = N-1; i >= 0; i--)
		vetorIntercalado[(i*2)+1] = W[i];
	return 0;
}

int main()
{
	int V[N], W[N], i, vetorIntercalado[2*N];
	for (i = 0; i < N; i++)
		scanf("%d", &V[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &W[i]);
	intercalar(V, W, vetorIntercalado);	
	for (i = 0; i < 2*N; i++)
		printf("%d\t", vetorIntercalado[i]);
	return 0;
}
