#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	FILE *output, *input;
	char v;
	int array[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int stringLength;

	if ((input = fopen ("1_6input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("1_6output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	while((fscanf(input, "%c", &v)) != EOF) {
		printf("%c ", v);
		if(v == 'a' || v == 'A') {
			array[0]++;
		} else if (v == 'b' || v == 'B') {
			array[1]++;
		} else if (v == 'c' || v == 'C') {
			array[2]++;
		} else if (v == 'd' || v == 'D') {
			array[3]++;
		} else if (v == 'e' || v == 'E') {
			array[4]++;
		} else if (v == 'f' || v == 'F') {
			array[5]++;
		} else if (v == 'g' || v == 'G') {
			array[6]++;
		} else if (v == 'h' || v == 'H') {
			array[7]++;
		} else if (v == 'i' || v == 'I') {
			array[8]++;
		} else if (v == 'j' || v == 'J') {
			array[9]++;
		} else if (v == 'k' || v == 'K') {
			array[10]++;
		} else if (v == 'l' || v == 'L') {
			array[11]++;
		} else if (v == 'm' || v == 'M') {
			array[12]++;
		} else if (v == 'n' || v == 'N') {
			array[13]++;
		} else if (v == 'o' || v == 'O') {
			array[14]++;
		} else if (v == 'p' || v == 'P') {
			array[15]++;
		} else if (v == 'q' || v == 'Q') {
			array[16]++;
		} else if (v == 'r' || v == 'R') {
			array[17]++;
		} else if (v == 's' || v == 'S') {
			array[18]++;
		} else if (v == 't' || v == 'T') {
			array[19]++;
		} else if (v == 'u' || v == 'U') {
			array[20]++;
		} else if (v == 'v' || v == 'V') {
			array[21]++;
		} else if (v == 'w' || v == 'W') {
			array[22]++;
		} else if (v == 'x' || v == 'X') {
			array[23]++;
		} else if (v == 'y' || v == 'Y') {
			array[24]++;
		} else if (v == 'z' || v == 'Z') {
			array[25]++;
		}
	}
	
	int i;
	for(i=0; i<26; i++){
		if(array[i] != 0) {
			printf("%c: %i, ", 65+i, array[i]);
			fprintf(output, "%c: %i, ", 65+i, array[i]);
		}
	}

	fclose (input);
	fclose (output);
	return 0;
}
