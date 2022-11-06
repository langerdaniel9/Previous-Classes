#include <stdio.h>

//State 0 = invalid
//State 1 = C
//State 2 = Y
//State 3 = B
//State 4 = O
//State 4 = T

int main() {
	int prevState = 0;
	
	int state [6][6] = 
	{
		{0,1,0,0,0,0},
		{0,1,2,0,0,0},
		{0,1,0,3,0,0},
		{0,1,0,0,4,0},
		{0,1,0,0,0,5},
		{5,5,5,5,5,5},
	};
	
	int output [6] = {0,0,0,0,0,1};
	
	while(1) {
		int currentState = 0;
		
		printf("Enter a character:\n");
		char input = getchar();
		getchar();
		
		if(input == 'C') {
			currentState = state[prevState][1];
		} else if(input == 'Y') {
			currentState = state[prevState][2];
		}  else if(input == 'B') {
			currentState = state[prevState][3];
		}  else if(input == 'O') {
			currentState = state[prevState][4];
		}  else if(input == 'T') {
			currentState = state[prevState][5];
		} else {
			currentState = state[prevState][0];
		}
		
		//printf("output[%i][%i]\n", prevState, currentState);
		printf("Output is %i\n", output[currentState]);
		prevState = currentState;
	}
	
	return 0;
}
