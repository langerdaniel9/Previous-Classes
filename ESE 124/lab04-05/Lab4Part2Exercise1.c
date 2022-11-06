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
		int index = 0;
		int length = strlen(v);
		
		for(index; index<length;index++) {
			switch(v[index]) {
				case '+': {
					fprintf(output, "PLUS ");
					printf("PLUS ");
					break;
				}
				case '-': {
					fprintf(output, "MINUS ");
					printf("MINUS ");
					break;
				}
				case '*': {
					fprintf(output, "MULTIPLY ");
					printf("MULTIPLY ");
					break;
				}
				case '/': {
					fprintf(output, "DIVIDE ");
					printf("DIVIDE ");
					break;
				}
				case '%': {
					fprintf(output, "MODULO ");
					printf("MODULO ");
					break;
				}
				case '@': {
					fprintf(output, "AT ");
					printf("AT ");
					break;
				}
				case '&': {
					fprintf(output, "BITWISE AND ");
					printf("BITWISE AND ");
					break;
				}
				case '^': {
					fprintf(output, "BITWISE XOR ");
					printf("BITWISE XOR ");
					break;
				}
			}
		}
	}

	fclose (input);
	fclose (output);
	return 0;
}

