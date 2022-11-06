// Read two numbers, and check whether the numbers are even or odd. Swap the two numbers.
// Then, find the largest number among the three numbers entered by the user.

#include <stdio.h>

int main()
{
	int num1, num2;
	printf("Type in two numbers separated by a space\n");
	scanf("%i %i", &num1, &num2);

	if (num1 % 2 == 0)
	{
		printf("%i is even\n", num1);
	}
	else
	{
		printf("%i is odd\n", num1);
	}

	if (num2 % 2 == 0)
	{
		printf("%i is even\n", num2);
	}
	else
	{
		printf("%i is odd\n", num2);
	}

	int temp = num1;
	num1 = num2;
	num2 = temp;

	if (num1 > num2)
	{
		printf("Num1 (%i) is the largest number\n", num1);
	}
	else if (num1 < num2)
	{
		printf("Num2 (%i) is the largest number\n", num2);
	}
	else
	{
		printf("Both numbers are equal.\n");
	}
}
