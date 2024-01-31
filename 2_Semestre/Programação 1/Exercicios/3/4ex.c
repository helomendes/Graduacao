#include <stdio.h>
#include <math.h>
#define N 3

int distEuclidiana(float v[], float w[], float x[], float y[])
{
	float menorDistancia = sqrt((x[0] - v[0])*(x[0] - v[0]) + (y[0] - w[0])*(y[0] - w[0]));
	int indice = 0;
	for (int i = 1; i < N; i++)
	{
		float dist = sqrt((x[0] - v[i])*(x[0] - v[i]) + (y[0] - w[i])*(y[0] - w[i]));
		if (dist < menorDistancia)
			indice = i;
	}
	return indice;
}

int main()
{
	int distancia;
	float v[N], w[N];
	float x[1], y[1];
	for (int i = 0; i < N; i++)
		scanf("%f %f", &v[i], &w[i]);
	scanf("%f %f", &x[0], &y[0]);
	distancia = distEuclidiana(v, w, x, y);
	printf("v[%d] = %.1f e w[%d] = %.1f\n", distancia, v[distancia], distancia, w[distancia]);
	return 0;
}
