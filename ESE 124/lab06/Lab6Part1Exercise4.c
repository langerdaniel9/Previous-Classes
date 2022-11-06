#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	FILE *output, *input;
	char v [32];
	int posNums, negNums, zero;

	if ((input = fopen ("1_4input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("1_4output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	while (fscanf (input, "%s", v) != EOF) {

		printf("%s ", v);
		int current = atoi(v);
		if(current > 0) {
			posNums++;
		} else if(current==0) {
			zero++;
		} else {
			negNums++;
		}
		
	}
	
	printf("\npos = %i, zero = %i, neg = %i", posNums, zero, negNums);
	fprintf(output, "Positive = %i, Zero = %i, Negative = %i", posNums, zero, negNums);

	fclose (input);
	fclose (output);
	return 0;
}
