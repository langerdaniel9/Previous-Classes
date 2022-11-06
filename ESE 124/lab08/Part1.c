#include <stdlib.h>
#include <stdio.h>

int my_isalpha(char input) {
	if((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')){
		return 1;
	} else {
		return 0;
	}
}

int my_isdigit(char input) {
	if(input >= 48 && input <= 57){
		return 1;
	} else {
		return 0;
	}
}

int my_alnum(char input) {
	if((input >= 48 && input <= 57) || (input >= 65 && input <= 90) || (input >= 97 && input <= 122)){
		return 1;
	} else {
		return 0;
	}
}

int my_is_upper(char input) {
	if(input >= 'A' && input <= 'Z'){
		return 1;
	} else {
		return 0;
	}
}

int my_is_lower(char input) {
	if(input >= 'a' && input <= 'z'){
		return 1;
	} else {
		return 0;
	}
}

int my_to_upper(char input) {
	if(input >= 'a' && input <= 'z'){
		return input-32;
	} else {
		return input;
	}
}

int my_to_lower(char input) {
	if(input >= 'A' && input <= 'Z'){
		return input+32;
	} else {
		return input;
	}
}

int main() {
	char isAlpha1 = '*', isAlpha2 = '%';
	char isDigit1 = '*', isDigit2 = '%';
	char alnum1 = '*', alnum2 = '%';
	char isUpper1 = '*', isUpper2 = '%';
	char isLower1 = '*', isLower2 = '%';
	char toUpper1 = '*', toUpper2 = '%';
	char toLower1 = '*', toLower2 = '%';
	
	
	printf("my_isalpha(%c) returns %i\n", isAlpha1, my_isalpha(isAlpha1));
	printf("my_isalpha(%c) returns %i\n", isAlpha2, my_isalpha(isAlpha2));
	
	printf("my_isdigit(%c) returns %i\n", isDigit1, my_isdigit(isDigit1));
	printf("my_isdigit(%c) returns %i\n", isDigit2, my_isdigit(isDigit2));
	
	printf("my_alnum(%c) returns %i\n", alnum1, my_alnum(alnum1));
	printf("my_alnum(%c) returns %i\n", alnum2, my_alnum(alnum2));
	
	printf("my_is_upper(%c) returns %i\n", isUpper1, my_is_upper(isUpper1));
	printf("my_is_upper(%c) returns %i\n", isUpper2, my_is_upper(isUpper2));
	
	printf("my_is_lower(%c) returns %i\n", isLower1, my_is_lower(isLower1));
	printf("my_is_lower(%c) returns %i\n", isLower2, my_is_lower(isLower2));
	
	printf("my_to_upper(%c) returns %c\n", toUpper1, my_to_upper(toUpper1));
	printf("my_to_upper(%c) returns %c\n", toUpper2, my_to_upper(toUpper2));
	
	printf("my_to_lower(%c) returns %c\n", toLower1, my_to_lower(toLower1));
	printf("my_to_lower(%c) returns %c\n", toLower2, my_to_lower(toLower2));
	return 0;
}
