#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	FILE *input, *output;
	char v [32];


	if ((input = fopen ("input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("1_2output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	while (fscanf (input, "%s", v) != EOF) {
		if(v[0] == '_' || (v[0] >= 97 && v[0] <= 122) || (v[0] >= 65 && v[0] <= 90)) {
			int length = strlen(v);
			int i=0;
			
			for(i; i<length; i++) {
				if(v[i] == '_' || (v[i] >= 97 && v[i] <= 122) || (v[i] >= 65 && v[i] <= 90)) {
					fprintf(output, "%c", v[i]);
					printf("%c", v[i]);	
				}
			}
			

		}

	}

	fclose (input);
	fclose (output);
	return 0;
}

