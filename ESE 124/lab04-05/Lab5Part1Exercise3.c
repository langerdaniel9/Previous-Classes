#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () {
	FILE *input, *output;
	char str [100];
	char first [10];
	char initial[] = "INITIAL", left[] = "LEFT", right[] = "RIGHT", up[] = "UP", down[] = "DOWN";
	int i;
	float x, y;
	float number;
	
	if ((input = fopen ("input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	if ((output = fopen ("output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	while (fgets(str, 100, input) != NULL) {
		sscanf(str, "%s", first);
		
		if(strcmp(first, initial) == 0) {
			sscanf(str, "%s (%f, %f)", first, &x, &y);
			printf("Started at (%f, %f)\n", x, y);
			continue;
		} else if (strcmp(first, left) == 0) {
			sscanf(str, "%s %f", first, &number);
			x -= number;
		} else if (strcmp(first, right) == 0) {
			sscanf(str, "%s %f", first, &number);
			x += number;
		} else if (strcmp(first, up) == 0) {
			sscanf(str, "%s %f", first, &number);
			y += number;
		} else if (strcmp(first, down) == 0) {
			sscanf(str, "%s %f", first, &number);
			y -= number;
		}
		printf("Moved to (%f, %f)\n", x, y);
	}

	printf("Final position (%f, %f)", x, y);
	fprintf(output, "Final position (%f, %f)", x, y);

	fclose (input);
	fclose (output);
	return 0;
}



