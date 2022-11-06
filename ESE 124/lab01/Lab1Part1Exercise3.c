// Extend exercise 2, so that the C program continuously reads
// a sequence of rows of the specified format.

#include <stdio.h>
#include <string.h>

int main()
{

	int i;
	for (i = 0; i < 5; ++i)
	{

		char input[100];
		int month, day, year;
		printf("Enter a date in the format month/day/year:\n", &input);
		scanf("%s", input);
		sscanf(input, "%i/%i/%i", &month, &day, &year);
		// printf("month is %i", month);
		if (month < 1 || month > 12)
		{
			printf("Invalid Date\n\n");
			break;
		}
		else if (day < 1)
		{
			printf("Invalid Date\n\n");
			break;
		}

		switch (month)
		{
		case 1:
			if (day > 31)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 2:
			if (day > 28)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 3:
			if (day > 31)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 4:
			if (day > 30)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 5:
			if (day > 31)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 6:
			if (day > 30)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 7:
			if (day > 31)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 8:
			if (day > 31)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 9:
			if (day > 30)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 10:
			if (day > 31)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 11:
			if (day > 30)
			{
				printf("Invalid Date\n\n");
				break;
			}
		case 12:
			if (day > 31)
			{
				printf("Invalid Date\n\n");
				break;
			}
		default:
			printf("Mo %i - Day %i - Ye %i\n\n", month, day, year);
		}
	}
}
