#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


FILE *input, *output, *sorted;
char line[100];
char v[50];

char str [100];
int array[1000];
int placeArray=0;
int i=0, placeString = 0, toAdd = 0;
char next;


int isDecimal(){
	i = placeString;
	while (isdigit(str[i]))
	{
		fprintf(sorted, "%c", str[i]);
		i++;
		toAdd++;
		if (str[i] == '.')
		{
			if (isdigit(str[i + 1]))
			{
				fprintf(sorted, ".");
			}
			i++;
			toAdd++;
			break;
		}
		else if (str[i] == 'e' || str[i] == 'E')
		{
			if(str[i+1] == '-') {
				fprintf(sorted, "%c%c", str[i], str[i+1]);
				i+=2;
				toAdd+=2;
			} else if(isdigit(str[i+1])) {
				fprintf(sorted, "%c", str[i]);
				i++;
			}
			while (isdigit(str[i])){
				fprintf(sorted, "%c", str[i]);
				i++;
				toAdd++;
			}
			break;
		}
	}

	while (isdigit(str[i]))
	{
		fprintf(sorted, "%c", str[i]);
		i++;
		toAdd++;
		if (str[i] == 'e' || str[i] == 'E')
		{
			if(str[i+1] == '-') {
				fprintf(sorted, "%c%c", str[i], str[i+1]);
				i+=2;
				toAdd+=2;
			} else if(isdigit(str[i+1])) {
				fprintf(sorted, "%c", str[i]);
				i++;
			}
			while (isdigit(str[i])){
				fprintf(sorted, "%c", str[i]);
				i++;
				toAdd++;
			}
			break;
		}
	}

	fprintf(sorted, "\n");
}


int final () {
	FILE *sorted, *output;
	float sum = 0;
	int count = 0;
	char holder [50];

	if ((sorted = fopen("sorted.txt", "r")) == NULL){
		printf("error: file cannot be opened\n");
		exit(1);
	}

	if ((output = fopen("output.txt", "a")) == NULL){
		printf("error: file cannot be opened\n");
		exit(1);
	}
	
	while (fscanf (sorted, "%s", holder) != EOF) {
		fprintf(output, "%s ", holder);
		sum += atof(holder);
		count++;
	}
	
	fprintf(output, "\nSum = %f | average = %f", sum, sum/count);
	
	
	fclose (sorted);
	fclose (output);
	
	return 0;
}


int main () {
	

	if ((input = fopen ("input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	if ((sorted = fopen ("sorted.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	if ((output = fopen ("output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	//Lab 4 Part B 1
	while (fgets(line, 100, input) != NULL) {
		fputs(line, output);
	}
	
	fclose (input);
	input = fopen ("input.txt", "r");
	fprintf(output, "\n\n");
	
	//Lab 4 Part B 2
	while (fscanf (input, "%s", v) != EOF) {
		if(v[0] == '_' || (v[0] >= 97 && v[0] <= 122) || (v[0] >= 65 && v[0] <= 90)) {
			int length = strlen(v);
			int i=0;
			
			for(i; i<length; i++) {
				if(v[i] == '_' || (v[i] >= 97 && v[i] <= 122) || (v[i] >= 65 && v[i] <= 90)) {
					fprintf(output, "%c", v[i]);
				}
			}
		}
	}
	
	fclose (input);
	input = fopen ("input.txt", "r");
	fprintf(output, "\n\n");
	
	//Lab 4 Part B 3
	while (fscanf (input, "%s", v) != EOF) {
		if(v[0] == '_' || (v[0] >= 97 && v[0] <= 122) || (v[0] >= 65 && v[0] <= 90)) {
			int length = strlen(v);
			int i=0;
			
			for(i; i<length; i++) {
				if(v[i] == '_' || (v[i] >= 97 && v[i] <= 122) || (v[i] >= 65 && v[i] <= 90)) {
					if(v[i] >= 97 && v[i] <= 122) {
						v[i] -= 32;
						fprintf(output, "%c", v[i]);
					} else {
						fprintf(output, "%c", v[i]);
					}
				}
			}
		}
	}
	
	fclose (input);
	input = fopen ("input.txt", "r");
	fprintf(output, "\n\n");
	
	//Lab 4 Part C 1
	while (fscanf (input, "%s", v) != EOF) {
		int index = 0;
		int length = strlen(v);
		
		for(index; index<length;index++) {
			switch(v[index]) {
				case '+': {
					fprintf(output, "PLUS ");
					break;
				}
				case '-': {
					fprintf(output, "MINUS ");
					break;
				}
				case '*': {
					fprintf(output, "MULTIPLY ");
					break;
				}
				case '/': {
					fprintf(output, "DIVIDE ");
					break;
				}
				case '%': {
					fprintf(output, "MODULO ");
					break;
				}
				case '@': {
					fprintf(output, "AT ");
					break;
				}
				case '&': {
					fprintf(output, "BITWISE AND ");
					break;
				}
				case '^': {
					fprintf(output, "BITWISE XOR ");
					break;
				}
			}
		}
	}
	
	fclose (input);
	input = fopen ("input.txt", "r");
	fprintf(output, "\n\n");
	
	//Lab 4 Part C 2
	while (fscanf (input, "%s", v) != EOF) {
		int index = 0;
		int length = strlen(v);
		
		for(index; index<length;index++) {
			if(v[index] == '+' || v[index] == '-' ||v[index] == '=' ||v[index] == '*'){
				if(v[index] == '+' && v[index+1] == '+') {
					fprintf(output, "INCREMENT ");
					index++;
				} else if(v[index] == '-' && v[index+1] == '-') {
					fprintf(output, "DECREMENT ");
					index++;
				} else if(v[index] == '+' && v[index+1] == '=') {
					fprintf(output, "(ADD ASSIGN) ");
					index++;
				} else if(v[index] == '*' && v[index+1] == '=') {
					fprintf(output, "(MULTIPLY ASSIGN) ");
					index++;
				} else if(v[index] == '=' && v[index+1] == '=') {
					fprintf(output, "EQUAL ");
					index++;
				} else if(v[index] == '+') {
					fprintf(output, "PLUS ");
				} else if(v[index] == '-') {
					fprintf(output, "MINUS ");
				} else if(v[index] == '=') {
					fprintf(output, "ASSIGN ");
				} else if(v[index] == '*') {
					fprintf(output, "MULTIPLY ");
				}
			} else if(v[index] == '*') {
				fprintf(output, "MULTIPLY ");
			} else if(v[index] == '/') {
				fprintf(output, "DIVIDE ");
			} else if(v[index] == '%') {
				fprintf(output, "MODULO ");
			} else if(v[index] == '@') {
				fprintf(output, "AT ");
			} else if(v[index] == '&') {
				fprintf(output, "BITWISE AND ");
			} else if(v[index] == '^') {
				fprintf(output, "BITWISE XOR ");
			}
		}
	}
		
	fclose (input);
	input = fopen ("input.txt", "r");
	fprintf(output, "\n\n");
	
	//Lab 4 Part C 3
	while (fscanf (input, "%s", v) != EOF) {
		int index = 0;
		int length = strlen(v);
		
		for(index; index<length;index++) {
			if(v[index] == '+' || v[index] == '-' ||v[index] == '=' ||v[index] == '*'){
				if(v[index] == '+' && v[index+1] == '+') {
					fprintf(output, "INCREMENT ");
					index++;
				} else if(v[index] == '-' && v[index+1] == '-') {
					fprintf(output, "DECREMENT ");
					index++;
				} else if(v[index] == '+' && v[index+1] == '=') {
					fprintf(output, "(ADD ASSIGN) ");
					index++;
				} else if(v[index] == '*' && v[index+1] == '=') {
					fprintf(output, "(MULTIPLY ASSIGN) ");
					index++;
				} else if(v[index] == '=' && v[index+1] == '=') {
					fprintf(output, "EQUAL ");
					index++;
				} else if(v[index] == '+') {
					fprintf(output, "PLUS ");
				} else if(v[index] == '-') {
					fprintf(output, "MINUS ");
				} else if(v[index] == '=') {
					fprintf(output, "ASSIGN ");
				} else if(v[index] == '*') {
					fprintf(output, "MULTIPLY ");
				}
			} else if(v[index] == '*') {
				fprintf(output, "MULTIPLY ");
			} else if(v[index] == '/') {
				fprintf(output, "DIVIDE ");
			} else if(v[index] == '%') {
				fprintf(output, "MODULO ");
			} else if(v[index] == '@') {
				fprintf(output, "AT ");
			} else if(v[index] == '&') {
				fprintf(output, "BITWISE AND ");
			} else if(v[index] == '^') {
				fprintf(output, "BITWISE XOR ");
			} else if(v[index] == '.') {
				fprintf(output, "DOT ");
			} else if(v[index] == ',') {
				fprintf(output, "COMMA ");
			} else if(v[index] == ';') {
				fprintf(output, "SEMICOLON ");
			} else if(v[index] == ':') {
				fprintf(output, "COLON ");
			}
		}
	}
	
	fclose (input);
	fprintf(output, "\n\n");
	fclose (output);
	fclose (sorted);
	
	
	input = fopen ("input.txt", "r");
	sorted = fopen("sorted.txt", "w");
	
	
	
	//Lab 5 Part B 2
	
	while (fgets(str, 100, input) != NULL) {
		i=0;
		int length = strlen(str);
		for(placeString = 0; placeString<length; placeString++) {
			toAdd = 0;
			if(str[placeString] == '+' || str[placeString] == '-') {
				if(isdigit(str[placeString+1])){
					fprintf(sorted, "%c", str[placeString]);
					i++;
					placeString++;
					isDecimal();
					if(toAdd != 1) {
						placeString += toAdd;
					}
				} else {
					i++;
					placeString++;
				}
			} else if (isdigit(str[placeString])) {
				isDecimal();
				if(toAdd != 1) {
					placeString += toAdd;
				}
			}
		}
	}
	
	fclose (sorted);
	fclose (input);
	final();
		
	return 0;
}
