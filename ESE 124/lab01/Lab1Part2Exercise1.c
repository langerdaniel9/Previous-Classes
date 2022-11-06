#include <stdio.h>

int main()
{
	float sum;
	while (1)
	{
		float number;
		printf("Enter a number:\n");
		scanf("%f", &number);
		sum += number;
		printf("The sum is: %.3f\n", sum);
	}
}
