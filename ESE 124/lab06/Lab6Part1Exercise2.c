#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	FILE *output, *input;
	char v [32];
	char array [16];
	int numChars;

	if ((input = fopen ("1_2input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("1_2output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	while (fscanf (input, "%s", v) != EOF) {

		int count;
		
		for(count = 0; count <strlen(v); count++) {
			if(v[count] != v[count+1]) {
				fprintf(output, "%c", v[count]);
				printf("%c", v[count]);
				//printf("%c %c, %i\n", v[count], v[count+1], v[count] == v[count+1]);
			} else {
				fprintf(output, "%c", v[count]);
				printf("%c", v[count]);
				//printf("%c %c, %i\n", v[count], v[count+1], v[count] == v[count+1]);
				count++;
			}
		}
		fprintf(output, "\n");
		printf("\n");

	}

	fclose (input);
	fclose (output);
	return 0;
}
