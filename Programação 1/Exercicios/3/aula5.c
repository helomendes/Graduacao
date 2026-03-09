#include <stdio.h>

int main()
{
	int temperatura = 25;
	while (temperatura <= 92)
	{
			if (temperatura >= 30 && temperatura <= 40)
			{
				printf("Placa de vídeo ociosa.\n");
				temperatura = 40;
			}
			if (temperatura > 60 && temperatura < 85)
			{
				printf("Placa sob carga.\n");
				temperatura = 85;
			}
			if (temperatura >= 83)
			{
				printf("Controle térmico em curso, limitando processamento.\n");
				temperatura = 92;
			}
			if (temperatura >= 92)
				printf("Temperatura crítica, desligando...\n");
			temperatura++;
	}
	return 0;
}
