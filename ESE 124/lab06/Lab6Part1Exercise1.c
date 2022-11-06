#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	FILE *output, *input;
	char v [32];
	char array [16];
	int numChars;

	if ((input = fopen ("1_1input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("1_1output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	while (fscanf (input, "%s", v) != EOF) {

		int count;
		int letters = 0;
		int otherChars = 0;
		for(count = 0; count < 15; count++) {
			char a = v[count];
			if((a <= 90 && a >= 60) || (a <= 122 && a >= 97)) {
				letters++;
			} else {
				otherChars++;
			}
		}
		if(letters >= otherChars*2) {
			printf("%s is a sparse array\n", v);
			fprintf(output, "%s is a sparse array\n", v);
		} else {
			printf("%s is not a sparse array\n", v);
			fprintf(output, "%s is not a sparse array\n", v);
		}
	}

	fclose (input);
	fclose (output);
	return 0;
}
