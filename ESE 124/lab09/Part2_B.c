#include <stdio.h>

int noValid() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='C') {
		printf("0\n");
		noValid();
	} else if (input == 'C') {
		printf("0\n");
		letterC();
	}
}

int letterC() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='Y') {
		printf("0\n");
		noValid();
	} else if(input == 'Y') {
		printf("0\n");
		letterY();
	}
}

int letterY() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='B') {
		printf("0\n");
		noValid();
	} else if (input == 'B') {
		printf("0\n");
		letterB();
	}
}

int letterB() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='O') {
		printf("0\n");
		noValid();
	} else if(input == 'O') {
		printf("0\n");
		letterO();
	}
}

int letterO() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='T') {
		printf("0\n");
		noValid();
	} else if(input == 'T') {
		printf("1\n");
		letterT();
	}
}

int letterT() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input) {
		printf("1\n");
		letterT();
	}
}


int main() {
	char input;
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='C') {
		printf("0\n");
		noValid();
	} else if(input == 'C') {
		printf("0\n");
		letterC();
	}
}
