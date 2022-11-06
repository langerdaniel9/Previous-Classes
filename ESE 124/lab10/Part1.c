#include <stdio.h>
#include <math.h>

float relError(int n, float x)
{
	float lnArray[] = {1.295836866004329, 7.235076682267303, 4.454719949364001, 7.090354888959125, 14.02585092994046};

	float error = fabs(x - lnArray[n]) / fabs(lnArray[n]);
	float precision = (1 - error) * 100;
	return precision;
}

float function1(float x)
{
	return sqrt(x);
}

float function2(float x)
{
	return log(x);
}

float function3(float x)
{
	return exp(x);
}

float function4(float x)
{
	return (x * x);
}

float function5(float x)
{
	return pow(x, 3);
}
float integral(float a, float b, float N, float (*curFunction)(float))
{
	int i;

	float deltaX = b - a;
	float step = deltaX / N;

	float sum = 0.0;

	for (i = 1; i <= (N); i++)
	{
		float area = ((curFunction(a + (step * (i - 1))) + curFunction(a + (step * (i)))) / 2) * step;
		sum += area;
	}

	return sum;
}

int main()
{
	int i;

	float *functionArray[] = {function1, function2, function3, function4, function5};
	char *functionNames[] = {"Square Root", "ln", "exponential", "square", "cubic"};

	for (i = 0; i < 5; i++)
	{
		float a, b, N;

		printf("%s function\n", functionNames[i]);

		printf("Left bound:\n");
		scanf("%f", &a);

		printf("Right bound:\n");
		scanf("%f", &b);

		printf("How many points:\n");
		scanf("%f", &N);

		printf("Integral value: %f\n\n", integral(a, b, N, functionArray[i]));
	}

	printf("The precision of the computed integrals the function ln with 10, 20, 40, 80, 160 discretization points:\n");

	printf("For 1 to 3: %.4f%%, %.4f%%, %.4f%%, %.4f%%, %.4f%%\n", relError(0, integral(1, 3, 10, function2)), relError(0, integral(1, 3, 20, function2)), relError(0, integral(1, 3, 40, function2)), relError(0, integral(1, 3, 80, function2)), relError(0, integral(1, 3, 160, function2)));
	printf("For 2 to 7: %.4f%%, %.4f%%, %.4f%%, %.4f%%, %.4f%%\n", relError(1, integral(2, 7, 10, function2)), relError(1, integral(2, 7, 20, function2)), relError(1, integral(2, 7, 40, function2)), relError(1, integral(2, 7, 80, function2)), relError(1, integral(2, 7, 160, function2)));
	printf("For 3 to 6: %.4f%%, %.4f%%, %.4f%%, %.4f%%, %.4f%%\n", relError(2, integral(3, 6, 10, function2)), relError(2, integral(3, 6, 20, function2)), relError(2, integral(3, 6, 40, function2)), relError(2, integral(3, 6, 80, function2)), relError(2, integral(3, 6, 160, function2)));
	printf("For 4 to 8: %.4f%%, %.4f%%, %.4f%%, %.4f%%, %.4f%%\n", relError(3, integral(4, 8, 10, function2)), relError(3, integral(4, 8, 20, function2)), relError(3, integral(4, 8, 40, function2)), relError(2, integral(4, 8, 80, function2)), relError(3, integral(4, 8, 160, function2)));
	printf("For 1 to 10: %.4f%%, %.4f%%, %.4f%%, %.4f%%, %.4f%%\n", relError(4, integral(1, 10, 10, function2)), relError(4, integral(1, 10, 20, function2)), relError(4, integral(1, 10, 40, function2)), relError(4, integral(1, 10, 80, function2)), relError(4, integral(1, 10, 160, function2)));
}
