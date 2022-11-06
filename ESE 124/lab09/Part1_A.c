#include <stdio.h>

int noValid() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='F') {
		printf("0\n");
		noValid();
	} else if (input == 'F') {
		printf("0\n");
		letterF();
	}
}

int letterF() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='R') {
		printf("0\n");
		noValid();
	} else if(input == 'R') {
		printf("0\n");
		letterR();
	}
}

int letterR() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='O') {
		printf("0\n");
		noValid();
	} else if (input == 'O') {
		printf("0\n");
		letterO();
	}
}

int letterO() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='G') {
		printf("0\n");
		noValid();
	} else if(input == 'G') {
		printf("1\n");
		letterG();
	}
}

int letterG() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input) {
		printf("1\n");
		letterG();
	}
}


int main() {
	char input;
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='F') {
		printf("0\n");
		noValid();
	} else if(input == 'F') {
		printf("0\n");
		letterF();
	}
}
