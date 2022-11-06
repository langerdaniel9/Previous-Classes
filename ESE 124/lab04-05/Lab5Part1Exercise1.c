#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char str [100];
int array[1000];
int placeArray=0;
int i=0, placeString = 0, toAdd = 0;
char next;

FILE *input, *sorted;


int isDecimal () {
	i = placeString;
	while(isdigit(str[i])) {
		fprintf(sorted, "%c", str[i]);
		i++;
		toAdd++;
		if(str[i] == '.') {
			if(isdigit(str[i+1])){
				fprintf(sorted, ".");
			}
			i++;
			toAdd++;
			break;
		}
	}
	
	while(isdigit(str[i])) {
		fprintf(sorted, "%c", str[i]);
		i++;
		toAdd++;
	}
	
	fprintf(sorted, "\n");
}


int final () {
	FILE *sorted, *output;
	float sum = 0;
	int count = 0;
	char holder [50];



	if ((sorted = fopen ("sorted.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	
	//while (fscanf (input, "%s", v) != EOF) {
	
	while (fscanf (sorted, "%s", holder) != EOF) {
		fprintf(output, "%s ", holder);
		sum += atof(holder);
		count++;
	}
	
	fprintf(output, "\nSum = %f | average = %f", sum, sum/count);
	
	
	fclose (sorted);
	fclose (output);
	
	return 0;
}


int main () {

	
	if ((input = fopen ("input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	if ((sorted = fopen ("sorted.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	while (fgets(str, 100, input) != NULL) {
		i=0;
		int length = strlen(str);
		
		for(placeString = 0; placeString<length; placeString++) {
			toAdd = 0;
			if(str[placeString] == '+' || str[placeString] == '-') {
				if(isdigit(str[placeString+1])){
					fprintf(sorted, "%c", str[placeString]);
					i++;
					placeString++;
					isDecimal();
					if(toAdd != 1) {
						placeString += toAdd;
					}
				} else {
					i++;
					placeString++;
				}
			} else if (isdigit(str[placeString])) {
				isDecimal();
				if(toAdd != 1) {
					placeString += toAdd;
				}
			}
		}
	}

	


	fclose (input);
	fclose (sorted);
	final();
}



