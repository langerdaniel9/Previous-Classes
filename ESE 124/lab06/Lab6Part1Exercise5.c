#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main () {
	FILE *output, *input;
	char v [32];

	if ((input = fopen ("1_5input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("1_5output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	int x; //array length
	int k; //number to print
	
	printf("How many numbers from the input file?\n");
	scanf("%i", &x);
	
	printf("How many to print as the largest?\n");
	scanf("%i", &k);

	char array [x+1];
	int count = 0;

	for (count; count<x; count++) {
		fscanf (input, "%s", v);
		int number = atoi(v);
		array[count] = number;
	}
	
	bool loop = true;
	int placeholder;
	while (loop){
		loop = false;
		int j;
		for(j = 0; j < x-1; j++) {
			if(array[j] < array[j+1]) {
				placeholder = array[j];
				array[j] = array[j+1];
				array[j+1] = placeholder;
				loop = true;
			}
		}
	}

	int i;
	printf("\nThe %i largest numbers are: ", k);
	for(i = 0; i<k; i++) {
		printf("%i ", array[i]);
	}
	
	int l;
	fprintf(output, "K = %i\nX = %i\n", k, x);
		for(l = 0; l<k; l++) {
			fprintf(output, "%i ", array[l]);
	}

	fclose (input);
	fclose (output);
	return 0;
}
