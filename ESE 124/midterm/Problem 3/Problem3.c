#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	FILE *input;
	char v [32];
	char array[1000];
	int occurances = 0;
	int count = 0;
	int i;
	int vowels = 0, consonants = 0;

	if ((input = fopen ("input.txt", "r")) == NULL) {
		printf ("error: file cannot be opened\n");
		exit (1);
	}

//Get all of the characters from the input file and put them into an array, character by character, ignoring spaces and setting all to lowercase
	while (fscanf (input, "%s", v) != EOF) {
		int length = strlen(v);
		for(i=0; i<length; i++) {
			if(v[i] >= 65 && v[i] <= 90) {
				array[count] = v[i]+32;
			} else {
				array[count] = v[i];	
			}
		count++;
		}
	}

//If an occurance of 'bear' is found, increase the counter
	for(i=0; i<count; i++) {
		
		if(array[i] == 'b' && array[i+1] == 'e' && array[i+2]  == 'a' && array[i+3] == 'r') {
			occurances ++;
		}
	}
	
	printf("There are %i occurances of bear\n", occurances);
	
//Count the occurances of vowels and consonants
	for(i=0; i<count; i++) {
		if(array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u') {
			vowels++;
		}else if (array[i] == 'b' || array[i] == 'c' || array[i] == 'd' || array[i] == 'f' || array[i] == 'g' || array[i] == 'h' || array[i] == 'j' || array[i] == 'k' || array[i] == 'l' || array[i] == 'm' || array[i] == 'n' || array[i] == 'p' || array[i] == 'q' || array[i] == 'r' || array[i] == 's' || array[i] == 't' || array[i] == 'v' || array[i] == 'w' || array[i] == 'x' || array[i] == 'y' || array[i] == 'z'){
			consonants++;
		}
	}
	
	printf("There are %i vowels and %i consonants", vowels, consonants);
	
	fclose (input);
	return 0;
}
