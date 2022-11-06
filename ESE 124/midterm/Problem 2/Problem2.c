#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	FILE *input;
	char v [32];
	float negArray[100];
	float posArray[100];
	int j;
	int posCount=0, negCount=0;
	float posSum=0, negSum = 0;

	if ((input = fopen ("decimals.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

//Get all numbers from the input file and put them into their respective arrays if they are negative or positive
	while (fscanf (input, "%s", v) != EOF) {
		float current = atof(v);
		if(current > 0) {
			posArray[posCount] = current;
			posCount++;
		} else if(current < 0) {
			negArray[negCount] = current;
			negCount++;
		}
	}
	
//get the sum for all of the positive numbers in the positive array
	for(j = 0; j<posCount; j++) {
		posSum += posArray[j];
	}
	
//get the sum for all of the negatie numbers in the negative array
	for(j=0; j<negCount; j++) {
		negSum += negArray[j];
	}
	
//print result
	printf("Negative sum = %f\n", negSum);
	printf("Positive sum = %f\n", posSum);

	fclose (input);
	return 0;
}
