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
			if(v[index] == '+' || v[index] == '-' ||v[index] == '=' ||v[index] == '*'){
				if(v[index] == '+' && v[index+1] == '+') {
					fprintf(output, "INCREMENT ");
					printf("INCREMENT ");
					index++;
				} else if(v[index] == '-' && v[index+1] == '-') {
					fprintf(output, "DECREMENT ");
					printf("DECREMENT ");
					index++;
				} else if(v[index] == '+' && v[index+1] == '=') {
					fprintf(output, "(ADD ASSIGN) ");
					printf("(ADD ASSIGN) ");
					index++;
				} else if(v[index] == '*' && v[index+1] == '=') {
					fprintf(output, "(MULTIPLY ASSIGN) ");
					printf("(MULTIPLY ASSIGN) ");
					index++;
				} else if(v[index] == '=' && v[index+1] == '=') {
					fprintf(output, "EQUAL ");
					printf("EQUAL ");
					index++;
				} else if(v[index] == '+') {
					fprintf(output, "PLUS ");
					printf("PLUS ");
				} else if(v[index] == '-') {
					fprintf(output, "MINUS ");
					printf("MINUS ");
				} else if(v[index] == '=') {
					fprintf(output, "ASSIGN ");
					printf("ASSIGN ");
				} else if(v[index] == '*') {
					fprintf(output, "MULTIPLY ");
					printf("MUTIPLY ");
				}
			} else if(v[index] == '*') {
				fprintf(output, "MULTIPLY ");
				printf("MULTIPLY ");
			} else if(v[index] == '/') {
				fprintf(output, "DIVIDE ");
					printf("DIVIDE ");
			} else if(v[index] == '%') {
				fprintf(output, "MODULO ");
				printf("MODULO ");
			} else if(v[index] == '@') {
				fprintf(output, "AT ");
				printf("AT ");
			} else if(v[index] == '&') {
				fprintf(output, "BITWISE AND ");
				printf("BITWISE AND ");
			} else if(v[index] == '^') {
				fprintf(output, "BITWISE XOR ");
				printf("BITWISE XOR ");
			} else if(v[index] == '.') {
				fprintf(output, "DOT ");
				printf("DOT ");
			} else if(v[index] == ',') {
				fprintf(output, "COMMA ");
				printf("COMMA ");
			} else if(v[index] == ';') {
				fprintf(output, "SEMICOLON ");
				printf("SEMICOLON ");
			} else if(v[index] == ':*') {
				fprintf(output, "COLON ");
				printf("COLON ");
			}
		}
	}

	fclose (input);
	fclose (output);
	return 0;
}

