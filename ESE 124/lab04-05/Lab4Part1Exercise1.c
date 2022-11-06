#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main () {
	FILE *input, *output;
	char line[100];
	

	if ((input = fopen ("input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	if ((output = fopen ("output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	while (fgets(line, 100, input) != NULL) {
		fputs(line, output);
	}
	
	fclose (input);
	fclose (output);
	return 0;
}
