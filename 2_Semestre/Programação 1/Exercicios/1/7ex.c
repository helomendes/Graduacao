#include <stdio.h>
#define MAX 1024

int main()
{
	int n, V[MAX], L[MAX], cont = 0, ind = -1;
	printf("Insira um inteiro: ");
	scanf("%d", &n);
	
	if (n > MAX)
	{
		printf("Valor fornecido excede o valor máximo.");
		return 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("Insira um valor pra o vetor de índice %d: ", i);
		scanf("%d", &V[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		if (ind == -1)
		{
			ind++;
			L[ind] = V[i];
			cont++;
		}
		else
		{
			for(int j = 0; j <= ind; j++)
			{
				if(L[j] == V[i])
					cont++;
				else
				{
					//cont = 0; ainda n sei o que fazer nessa parte
					ind++;
					L[ind] = V[i];
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	printf("O elemento %d apareceu %d vezes", L[i], //cont[i]); talvez isso funcione, criar um vetor contador, cada elemento é quantas vezes apareceu

	return 0;
}
