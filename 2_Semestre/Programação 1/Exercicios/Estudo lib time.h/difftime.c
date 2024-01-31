#include <stdio.h>
#include <time.h>

int main(){
	struct tm tempo, tempo0;

	tempo.tm_sec = 2*42;
	tempo.tm_min = 1;
	tempo.tm_hour = 1;
	tempo.tm_mday = 1;
	tempo.tm_mon = 1;
	tempo.tm_year = 1;
	tempo.tm_wday = 1;

	tempo0.tm_sec = 42;
	tempo0.tm_min = 1;
	tempo0.tm_hour = 1;
	tempo0.tm_mday = 1;
	tempo0.tm_mon = 1;
	tempo0.tm_year = 1;
	tempo0.tm_wday = 1;

	printf("Diferença: %lf\n", difftime(mktime(&tempo), mktime(&tempo0)));
	return 0;
}
