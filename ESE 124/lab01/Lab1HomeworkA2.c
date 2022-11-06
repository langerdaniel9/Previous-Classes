// Check whether an alphabet entered by the user is a vowel or a consonant. 
// Then, find the ASCII value of a character.

#include <stdio.h>

int main () {
	char character;
	printf("Enter a character from the alphabet:\n");
	scanf("%c", &character);
	
	if(character == 'a' || character == 'e' ||character == 'i' ||character == 'o' ||character == 'u') {
		printf("%c is a vowel.\n", character);
	} else {
		printf("%c is a consonant.\n", character);
	}
	
	printf("ASCII value of %c is %d.", character, character);
}
