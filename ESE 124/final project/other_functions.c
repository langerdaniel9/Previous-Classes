#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/// Other Functions File ///

// Project Members: Daniel Langer, Alan George, and Kenneth Procacci //

void findDims()
{
	// scan a single row to find x_dim
	char rowForRowDim[100];
	input = fopen("maze.txt", "r");

	fgets(rowForRowDim, 100, input);
	int i;
	for (i = 0; i < strlen(rowForRowDim); i++)
	{
		if (rowForRowDim[i] == '*' || rowForRowDim[i] == ' ')
		{
			x_dim++;
		}
		else if (isdigit(rowForRowDim[i]))
		{
			while (isdigit(rowForRowDim[i + 1]))
			{
				i++;
			}
			x_dim++;
		}
	}
	fclose(input);

	// scan entire file to get y_dim
	input = fopen("maze.txt", "r");
	while (fgets(rowForRowDim, 100, input) != NULL)
	{
		y_dim++;
	}
	fclose(input);

	// printf("x = %i, y = %i", x_dim, y_dim);
}

void createArrays()
{
	// create maze array
	mazeArray = (char *)malloc(((x_dim) * (y_dim)) * sizeof(char *));

	// create deed and pheremone array
	deedArray = (int *)malloc(((x_dim) * (y_dim)) * sizeof(int *));
	pheromoneArray = (int *)malloc(((x_dim) * (y_dim)) * sizeof(int *));

	// initialize both to zero
	int i;
	for (i = 0; i < (x_dim * y_dim); i++)
	{
		deedArray[i] = 0;
		pheromoneArray[i] = 0;
	}
}

void scan()
{
	// Open file
	input = fopen("maze.txt", "r");

	// Scans the input file into the necessary arrays
	int i, j;
	for (i = 0; i < y_dim; i++)
	{
		char line[1000];
		fgets(line, 1000, input);
		int xthCharacter = 0;
		for (j = 0; j < strlen(line); j++)
		{
			// if its a number (deed value)
			if (isdigit(line[j]))
			{
				char temp[100];
				int k = 0;
				do
				{
					temp[k] = line[j];
					temp[k + 1] = '\0';
					k++;
					j++;
				} while (isdigit(line[j]));
				j--;
				deedArray[xthCharacter + (x_dim * i)] = atoi(temp);
				mazeArray[xthCharacter + (x_dim * i)] = ' ';
				xthCharacter++;
			}
			// otherwise its a wall or a space
			else if (line[j] == '*' || line[j] == ' ')
			{
				mazeArray[xthCharacter + (x_dim * i)] = line[j];
				xthCharacter++;
			}
		}
	}
}

void findStart()
{
	int i;

	// checks the left and right columns to check for the entrance
	for (i = 0; i < y_dim; i++)
	{
		// check the left column
		if (mazeArray[i * x_dim] == ' ')
		{
			currentPos.x = 0, currentPos.y = i; // Good
		}
		// check the right column
		else if (mazeArray[(i * x_dim) + x_dim - 1] == ' ')
		{
			currentPos.x = x_dim - 1, currentPos.y = i; //
		}
	}

	// checks the top and bottom rows to check for the entrance
	for (i = 0; i < x_dim; i++)
	{
		// check the top row
		if (mazeArray[i] == ' ')
		{
			currentPos.x = i, currentPos.y = 0; // Good
		}
		// check the bottom row
		else if (mazeArray[((y_dim - 1) * x_dim) + i] == ' ')
		{
			currentPos.x = i, currentPos.y = y_dim - 1; // Good
		}
	}

	// printf("starting position = (%i, %i)\n", currentPos.x, currentPos.y);
}

void checkIfOnDeed()
{
	// Checks to see if you are on the same space as a deed
	if (deedArray[currentPos.x + (currentPos.y * x_dim)] > 0)
	{
		fprintf(output, "Found a Deed worth %i at (%i, %i)\n", deedArray[currentPos.x + (currentPos.y * x_dim)], currentPos.x, currentPos.y);
		// If so collect that point value
		deedTotal += deedArray[currentPos.x + (currentPos.y * x_dim)];
		// Remove the deed from the current spot (it has already been picked up, and cant be picked up multiple times)
		deedArray[currentPos.x + (currentPos.y * x_dim)] = 0;
	}
}

void printMaze()
{
	int i;
	for (i = 0; i < x_dim * y_dim; i++)
	{
		if (i % (x_dim) == 0)
		{
			printf("\n");
		}
		if (pheromoneArray[i] == 1)
		{
			printf("|X|%i| ", deedArray[i]);
		}
		else
		{
			printf("|%c|%i| ", mazeArray[i], deedArray[i]);
		}
	}
}

void printDeed()
{
	int i, j;
	for (i = 0; i < y_dim; i++)
	{
		for (j = 0; j < x_dim; j++)
		{
			printf("%i ", deedArray[i + j * x_dim]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void printPheromone()
{
	int i, j;
	for (i = 0; i < y_dim; i++)
	{
		for (j = 0; j < x_dim; j++)
		{
			printf("%i ", pheromoneArray[i + j * x_dim]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void finished()
{
	fprintf(output, "\nEither the max number of steps has been reached or there are no more possible moves\n");
	fprintf(output, "Point total is %i", deedTotal);

	printMaze();
	printf("\n\n");
	printf("Point total is %i\n(Find the actions taken for this maze in the output.txt file)", deedTotal);
	exit(3);
}
