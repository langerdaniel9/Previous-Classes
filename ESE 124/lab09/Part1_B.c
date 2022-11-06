#include <stdio.h>

int noValid() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='M') {
		printf("0\n");
		noValid();
	} else if (input == 'M') {
		printf("0\n");
		letterM1();
	}
}

int letterM1() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='U') {
		printf("0\n");
		noValid();
	} else if(input == 'U') {
		printf("0\n");
		letterU1();
	}
}

int letterU1() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='R') {
		printf("0\n");
		noValid();
	} else if (input == 'R') {
		printf("0\n");
		letterR1();
	}
}

int letterR1() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='M') {
		printf("0\n");
		noValid();
	} else if(input == 'M') {
		printf("1\n");
		letterM2();
	}
}

int letterM2() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='U') {
		printf("0\n");
		noValid();
	} else if(input == 'U') {
		printf("0\n");
		letterU2();
	}
}

int letterU2() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='R') {
		printf("0\n");
		noValid();
	} else if (input == 'R') {
		printf("0\n");
		letterR2();
	}
}

int letterR2() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='S') {
		printf("0\n");
		noValid();
	} else if(input == 'S') {
		printf("1\n");
		letterS();
	}
}

int letterS() {
	char input;
	getchar();
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input) {
		printf("1\n");
		letterS();
	}
}


int main() {
	char input;
	printf("Enter a letter:\n");
	scanf("%c", &input);
	
	if(input !='M') {
		printf("0\n");
		noValid();
	} else if(input == 'M') {
		printf("0\n");
		letterM1();
	}
}
