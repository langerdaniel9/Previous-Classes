#include <stdio.h>

int noValid() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='A') {
		printf("0\n");
		noValid();
	} else if (input == 'A') {
		printf("0\n");
		letterA1();
	}
}

int letterA1() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='A') {
		printf("0\n");
		letterA1();
	} else if(input == 'A') {
		printf("0\n");
		letterA2();
	}
}

int letterA2() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='A') {
		printf("0\n");
		letterA2();
	} else if (input == 'A') {
		printf("1\n");
		letterA3();
	}
}

int letterA3() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='A') {
		printf("1\n");
		letterA3();
	} else if(input == 'A') {
		printf("0\n");
		invalid();
	}
}

int invalid() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input) {
		printf("0\n");
		invalid();
	}
}


int main() {
	char input;
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='A') {
		printf("0\n");
		noValid();
	} else if(input == 'A') {
		printf("0\n");
		letterA1();
	}
}
