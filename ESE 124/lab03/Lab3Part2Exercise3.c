#include <stdio.h>

int main () {
	
	char input;
	
	while(1) {
		printf("Enter a character:\n");
		scanf("%c", &input);
		
		if(input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') {
			printf("Input was a vowel.\n");
			getchar();
		}else if (input == 'b' || input == 'c' || input == 'd' || input == 'f' || input == 'g' || input == 'h' || input == 'j' || input == 'k' || input == 'l' || input == 'm' || input == 'n' || input == 'p' || input == 'q' || input == 'r' || input == 's' || input == 't' || input == 'v' || input == 'w' || input == 'x' || input == 'y' || input == 'z'){
			printf("Input was a consonant.\n");
			getchar();
		}else if (input == '#'){
			printf("Program has been ended.\n");
			return 0;		
		}else {
			printf("Input was invalid.\n");
			getchar();
		}
	}
}
