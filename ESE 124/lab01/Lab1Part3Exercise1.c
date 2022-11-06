// Write a C program that reads a floating point value (called x) and then a character that
// describes an operation using the values x, and then displays the result. Extend the program,
// so that the two operations are repeated 10 times.
//
// The operations associated to the characters are as follows:
// e   computes ex
// /   compute ln x
// r   computes the square root of x
// m   computes the absolute value of x

#include <stdio.h>
#include <math.h>

int main()
{
	float x;
	char operation;
	double result;
	int i;
	for (i = 0; i < 10; ++i)
	{
		printf("Enter a value:\n");
		scanf("%f", &x);
		getchar();
		printf("Enter an operation (e, /, r, m)\n");
		scanf("%c", &operation);

		switch (operation)
		{
		case 'e':
			result = exp(x);
			printf("Result is: %f\n\n", result);
			break;
		case '/':
			if (x <= 0)
			{
				printf("Invalid input.\n\n");
				break;
			}
			result = log(x);
			printf("Result is: %f\n\n", result);
			break;
		case 'r':
			if (x < 0)
			{
				printf("Invalid input.\n\n");
				break;
			}
			result = sqrt(x);
			printf("Result is: %f\n\n", result);
			break;
		case 'm':
			result = fabs(x);
			printf("Result is: %f\n\n", result);
			break;
		default:
			printf("Not valid, try again.\n\n");
			break;
		}
	}
	return 0;
}
