#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int isVowel(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		return true;
	}
	else {return false;}
}

int isVowelY(char c) {
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
		return true;
	}
	else {return false;}
}

char * toPigLatin(char * word) {
	int wordLen = strlen(word);
	int i, startingI=-3;
	bool isUppercase = false;
	char newWord[30];
	
	//checks if first letter is uppercase
	if(word[0]>=65 && word[0]<=90) {
		isUppercase = true;
	}
	
	//sets all characters to lowercase first
	for(i=0; i<wordLen; i++) {
		word[i] = tolower(word[i]);
	}
	
	//finds where to stop bringing characters to the end of the string
	while(startingI<0) {
		if(isVowel(word[0])) {
			startingI = 0;
			break;
		}
		for(i=1; i<wordLen; i++) {
			if(isVowelY(word[i])) {
				startingI = i;
				break;
			}
			
		}
	}
	
	//moves the characters from the end to the beginning
	for(i=startingI; i<wordLen; i++) {
		newWord[i-startingI] = word[i];
	}
	
	//moves the characters from the beginning to the end
	for(i=0; i<startingI; i++) {
		newWord[wordLen-startingI+i] = word[i];
	}
	
	//adds 'ay' or 'way'
	if(startingI == 0) {
		newWord[wordLen] = 'w';
		newWord[wordLen+1] = 'a';
		newWord[wordLen+2] = 'y';
		newWord[wordLen+3] = '\0';
	} else {
		newWord[wordLen] = 'a';
		newWord[wordLen+1] = 'y';
		newWord[wordLen+2] = '\0';
	}

	//replaces word with its new value
	for(i=0; i<strlen(newWord)+1; i++) {
		word[i] = newWord[i];
	}
	
	//changes to uppercase if needed
	if(isUppercase) {
		word[0] -= 32;
	}
	
	return word;
}

int main() {
	char WORD1[39], WORD2[39], WORD3[39], WORD4[39], WORD5[39];
	
	printf("Enter 5 words:\n");
	scanf("%s %s %s %s %s", &WORD1, &WORD2, &WORD3, &WORD4, &WORD5);
	
	printf("Pig Latin verion is:\n");
	printf("%s %s %s %s %s\n", toPigLatin(WORD1), toPigLatin(WORD2), toPigLatin(WORD3), toPigLatin(WORD4), toPigLatin(WORD5));
	
	return 0;
}
