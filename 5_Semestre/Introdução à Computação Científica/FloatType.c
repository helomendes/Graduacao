#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

typedef union
{
	int32_t i;
	float f;
	struct
	{
		uint32_t mantissa : 23;
		uint32_t exponent : 8;
		uint32_t sign : 1;
	} parts;
} Float_t;

void printFloat_t(Float_t num)
{
	printf("f:%1.9e, ix:0x%08X, s:%d, e:%d, mx:0x%06X\n",
			num.f, num.i, num.parts.sign, num.parts.exponent, num.parts.mantissa);
}

Float_t calculaEpsilonRelativo(Float_t num)
{
	Float_t epsilon;
	epsilon.f = num.f / 2.0f;
	while (num.f + epsilon.f / 2.0f > num.f)
		epsilon.f /= 2.0f;

	return epsilon;
}

int main()
{
	Float_t num, num2;
	num.f = 1.0f;
	num2.f = 1000.0f;

	printf("\nEpsilon: %1.15f, Epsilon: %1.19e\n", FLT_EPSILON, FLT_EPSILON);

	printf("\nDigite um numero: ");
	scanf("%f", &num.f);
	printf("\n Epsilon: ");
	printFloat_t(calculaEpsilonRelativo(num));

	return 0;
}
