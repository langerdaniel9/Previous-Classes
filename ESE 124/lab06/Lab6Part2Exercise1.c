#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main () {
	FILE *output, *input;
	int v[32];
	int array[30];
	int count;
	int possibleLength = 30;
	int arrayLength;

	if ((input = fopen ("2_1input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("2_1output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	for (count = 0; count<possibleLength; count++) {
		if(fscanf(input, "%s", v) == EOF) {
			break;
		} else {
			printf("%s\n", v);
		int number = atoi(v);
		array[count] = number;
		arrayLength++;
		}
	}

	bool loop = true;
	int placeholder;
	while (loop){
		loop = false;
		int j;
		for(j = 0; j < arrayLength-1; j++) {
			if(array[j] < array[j+1]) {
				placeholder = array[j];
				array[j] = array[j+1];
				array[j+1] = placeholder;
				loop = true;
			}
		}
	}

	int i;
	for(i = 0; i<arrayLength-1; i++) {
		printf("%i ", array[i]);
		fprintf(output, "%i ", array[i]);
	}
	

	fclose (input);
	fclose (output);
	return 0;
}
