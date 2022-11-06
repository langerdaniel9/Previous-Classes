// Write a C program that reads one row that includes the date in the following format
// Month/day/year
// And then displays the information in the following format
// Mo Month - Day day - Ye year

#include <stdio.h>
#include <string.h>

int main()
{

	char input[100];
	int month, day, year;
	printf("Enter a date in the format month/day/year:\n", &input);
	scanf("%s", input);
	sscanf(input, "%i/%i/%i", &month, &day, &year);
	if (month < 1 || month > 12)
	{
		printf("Invalid Date");
		return 0;
	}
	else if (day < 1)
	{
		printf("Invalid Date");
		return 0;
	}

	switch (month)
	{
	case 1:
		if (day > 31)
		{
			printf("Invalid Date");
			return 0;
		}
	case 2:
		if (day > 28)
		{
			printf("Invalid Date");
			return 0;
		}
	case 3:
		if (day > 31)
		{
			printf("Invalid Date");
			return 0;
		}
	case 4:
		if (day > 30)
		{
			printf("Invalid Date");
			return 0;
		}
	case 5:
		if (day > 31)
		{
			printf("Invalid Date");
			return 0;
		}
	case 6:
		if (day > 30)
		{
			printf("Invalid Date");
			return 0;
		}
	case 7:
		if (day > 31)
		{
			printf("Invalid Date");
			return 0;
		}
	case 8:
		if (day > 31)
		{
			printf("Invalid Date");
			return 0;
		}
	case 9:
		if (day > 30)
		{
			printf("Invalid Date");
			return 0;
		}
	case 10:
		if (day > 31)
		{
			printf("Invalid Date");
			return 0;
		}
	case 11:
		if (day > 30)
		{
			printf("Invalid Date");
			return 0;
		}
	case 12:
		if (day > 31)
		{
			printf("Invalid Date");
			return 0;
		}
	default:
		printf("Mo %i - Day %i - Ye %i\n", month, day, year);
	}
}
