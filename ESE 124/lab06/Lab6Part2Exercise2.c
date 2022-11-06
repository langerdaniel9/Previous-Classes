#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int compareArray(int first[], int second[]) {
	int firstLength = sizeof(first) / sizeof(first[0]); 
	int secondLength = sizeof(second) / sizeof(second[0]); 
	int j;
	if(firstLength >= secondLength) {
		for(j=0; j<firstLength; j++) {
			if(first[j] != second[j]) {
				return 0;
			}
		}
	} else {
		for(j=0; j<secondLength; j++) {
			if(first[j] != second[j]) {
				return 0;
			}
		}
	}
	return 1;
	
}


int main () {
	FILE *output, *input;
	char v[10];
	char array[10];
	char guessed[10];
	int wordLength;
	int i;
	int lives = 3;
	int correctly;

	if ((input = fopen ("2_2input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

	if ((output = fopen ("2_2output.txt", "w")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}
	
	while(fscanf(input, "%s", v) != EOF) {
	//printf("%s\n", v);
	wordLength = strlen(v);
	for(i=0; i<wordLength; i++) {
		array[i] = v[i];
	}
	//printf("%i\n", wordLength);
	}
	
	for(i=0; i<wordLength; i++) {
		guessed[i] = '-';
	}
	
	while(lives>0) {
		char guess;
		if(compareArray(array, guessed) == 1) {
			break;
		}
		printf("You have %i lives:\n    ", lives);
		for(i=0; i<wordLength; i++) {
			printf("%c", guessed[i]);
		}
		
		printf("\nGuess a letter:\n");;
		guess = getchar();
		getchar();

		if(guess<=122 && guess>=97) {
			guess-=32;

		}
		correctly = 0;
		for(i=0; i<wordLength; i++) {

			if(array[i] == guess) {

				guessed[i] = guess;
				correctly++;
			}
		}
		if(correctly == 0) {
			lives--;
		}
		
	}
	
	if(lives == 0) {
		printf("Sorry, but you didn't guess the word");
		fclose (input);
		fclose (output);
		return 0;
	}
	printf("    ");
	for(i=0; i<wordLength; i++) {
		printf("%c", guessed[i]);
	}
	printf("\nCongrats, you win!");



	fclose (input);
	fclose (output);
	return 0;
}








