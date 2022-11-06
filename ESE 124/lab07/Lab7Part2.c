#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char array[11][11][33];
int rowCount = 0;
int colCount[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



void deleteLines(int first, int last) {
	int i, j;
	//sets the rows to be deleted to empty strings
	for(i = first+1; i<last; i++) {
		for(j=0; j<10; j++) {
			array[i][j][0] = '\0';
		}
	}
	//moves rows to remove the empty spaces
	int linesToDelete = (last - first) - 1;
	
	for(i=first+1; i<10; i++) {
		for(j=0; j<10; j++) {
			strcpy(array[i][j], array[i + linesToDelete][j]);
		}
	}
	
	//clears the rows that were shifted down 
	
	for(i = 9; i>9-linesToDelete; i--) {
		for(j=0; j<10; j++) {
			array[i][j][0] = '\0';
		}
	}
	
}

void insertLine(int lineNumber, char newSentence[330]) {
	//moves rows to create an empty row
	int i, j, k;
	for(i=9; i>lineNumber; i--) {
		for(j=0; j<10; j++) {
			strcpy(array[i][j], array[i - 1][j]);
		}
	}
	
	for(i=0; i<10; i++) {
		array[lineNumber+1][i][0] = '\0';
	}
	
	//sorts through input string to separate the words
	int curCharCount = 0;
	char tempString[33];
	char separatedSentence[10][33];
	j = 0;
	k = 0;
	int ii;

	for(ii = 0; ii<10; ii++){
		separatedSentence[ii][0] = '\0';
	}
	
	for (curCharCount = 0; curCharCount < (strlen(newSentence)); curCharCount++)
	{
		if(newSentence[curCharCount+1] == ' ' || newSentence[curCharCount+1] == '\0') {
			if(j == 10) {
				break;
			}
			tempString[k] = newSentence[curCharCount];
			tempString[k + 1] = '\0';
			k++;
			strcpy(separatedSentence[j], tempString);
	
			k = 0;
			j++;
			curCharCount+=2;
		}
		tempString[k] = newSentence[curCharCount];
		tempString[k + 1] = '\0';
		k++;
	}
	
	//sets the newly created row to the inputted words
	
	for(i=0; i<10; i++) {
		strcpy(array[lineNumber+1][i], separatedSentence[i]);
		array[lineNumber+1][i+1][0] = '\0';
	}
}

int main()
{
	FILE *input, *output;
	int i = 0, j, k;
	int currentCharCount = 0;
	char line[500];
	char string[33];

	if ((input = fopen("input.txt", "r")) == NULL)
	{
		printf("error: file cannot be opened\n");
		exit(1);
	}

	if ((output = fopen("output.txt", "w")) == NULL)
	{
		printf("error: file cannot be created\n");
		exit(1);
	}
	
	int ii, jj;

	for(ii = 0; ii<10; ii++){
		for(jj = 0; jj<10; jj++) {
			array[ii][jj][0] = '\0';
		}
	}

	printf("The inputted array is:\n");

	while (fgets(line, 100, input) != NULL && i < 10)
	{
		j = 0;
		k = 0;
		for (currentCharCount = 0; currentCharCount < (strlen(line)); currentCharCount++)
		{
			if (isprint(line[currentCharCount]) && line[currentCharCount] != ' ')
			{
				string[k] = line[currentCharCount];
				string[k + 1] = '\0';
				k++;
			}
			else
			{
				strcpy(array[i][j], string);

				k = 0;
				j++;
				colCount[i]++;
			}
		}

		rowCount++;
		i++;
	}

	// prints the array
	for (i = 0; i < rowCount; i++)
	{
		for (j = 0; j < colCount[i]; j++)
		{
			printf("'%s' ", array[i][j]);
		}
		printf("\n");
	}
	
	char command[20];
	
	while(strcmp(command, "E") != 0) {
		printf("\nEnter a command, or type \'help\' to see the list of commands:\n");
		scanf("%s", command);
		//printf("command = %s", command);
		
		if(strcmp(command, "help") == 0) {
			printf("I   |   Insert new line with custom input\n");
			printf("D   |   Delete lines between a and b\n");
			printf("R   |   Replace lines between a and b with custom input\n");
			printf("E   |   Finish Editing\n");
		} else if(strcmp(command, "E") == 0) 
		{
			printf("Editing finished\n");
			
			printf("The resulting array is:\n");
			
			// prints the array
			//bool printNL = true;
			for (i = 0; i < 10; i++)
			{
				for (j = 0; j < 10; j++)
				{
					if(array[i][j][0] != '\0') {
						printf("'%s' ", array[i][j]);
						fprintf(output, "%s ", array[i][j]);
						//printNL = true;
					} //else {
					//	printNL = false;
					//}
				}
				//if(printNL == true) {
					printf("\n");
					fprintf(output, "\n");
				//}
			}
			printf("Resulting array has been saved to output file.");
			return 0;
		} 
		else if(strcmp(command, "I") == 0) 
		{
			int newLine;
			char inputLine[330];
			printf("Enter the line after which to insert:\n");
			scanf("%i", &newLine);
			getchar();
			printf("Enter the new line to be inserted:\n");
			gets(inputLine);
			
			insertLine(newLine, inputLine);
			
		} else if(strcmp(command, "D") == 0) 
		{
			int firstLine, lastLine;
			printf("Enter the first line that gets deleted:\n");
			scanf("%i", &firstLine);
			printf("Enter the last line that gets deleted:\n");
			scanf("%i", &lastLine);
			deleteLines(firstLine, lastLine);
			
		} else if(strcmp(command, "R") == 0) 
		{
			int firstLineR, lastLineR;
			char inputLineR[330];
			
			printf("Enter the first line that gets deleted:\n");
			scanf("%i", &firstLineR);
			printf("Enter the last line that gets deleted:\n");
			scanf("%i", &lastLineR);
			getchar();
			deleteLines(firstLineR, lastLineR);
			
			printf("Enter the new line to be inserted:\n");
			gets(inputLineR);
			
			insertLine(firstLineR, inputLineR);
		}
	}
	



	return 0;
}


