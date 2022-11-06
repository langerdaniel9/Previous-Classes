#include <stdio.h>

int main () {
	
	while(1) {
		unsigned int input1, input2, result;
		char operation;
		
		printf("Enter the first hex value:\n");
		scanf("%x", &input1);
		
		printf("Enter the second hex value:\n");
		scanf("%x", &input2);
		getchar();
		
		printf("Enter the operation (&, |, or ^):\n");
		scanf("%c", &operation);
		
		switch(operation) {
			case '&': {
				result = input1&input2;
				printf("Result is %x\n", result);
				break;
			}
			case '|': {
				result = input1|input2;
				printf("Result is %x\n", result);
				break;
			}
			case '^': {
				result = input1^input2;
				printf("Result is %x\n", result);
				break;
			}
			default : {
				printf("That is not a valid operation.\n");
				break;
			}
		}
	}
	return 0;
}
