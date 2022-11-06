#include <stdio.h>

//State 0 = invalid
//State 1 = M1
//State 2 = U1
//State 3 = R1
//State 4 = M2
//State 5 = U2
//State 6 = R2
//State 7 = S

int main() {
	int prevState = 0;
	
	int state [8][5] = 
	{
		{0,1,0,0,0},
		{0,1,2,0,0},
		{0,1,0,3,0},
		{0,4,0,0,0},
		{0,1,5,0,0},
		{0,1,0,6,0},
		{0,4,0,0,7},
		{7,7,7,7,7}
	};
	
	int output [8] = {0,0,0,0,0,0,0,1};
	
	while(1) {
		int currentState = 0;
		
		printf("Enter a character:\n");
		char input = getchar();
		getchar();
		
		if(input == 'M') {
			currentState = state[prevState][1];
		} else if(input == 'U') {
			currentState = state[prevState][2];
		} else if(input == 'R') {
			currentState = state[prevState][3];
		} else if(input == 'S') {
			currentState = state[prevState][4];
		} else {
			currentState = state[prevState][0];
		}
		
		//printf("output[%i][%i]\n", prevState, currentState);
		printf("Output is %i\n", output[currentState]);
		prevState = currentState;
	}
	
	return 0;
}
