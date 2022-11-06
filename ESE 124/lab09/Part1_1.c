#include <stdio.h>

//State 0 = invalid
//State 1 = F
//State 2 = R
//State 3 = O
//State 4 = G

int main() {
	int prevState = 0;
	
	int state [5][5] = 
	{
		{0,1,0,0,0},
		{0,1,2,0,0},
		{0,1,0,3,0},
		{0,1,0,0,4},
		{4,4,4,4,4}
	};
	
	int output [5] = {0,0,0,0,1};
	
	while(1) {
		int currentState = 0;
		
		printf("Enter a character:\n");
		char input = getchar();
		getchar();
		
		if(input == 'F') {
			currentState = state[prevState][1];
		} else if(input == 'R') {
			currentState = state[prevState][2];
		} else if(input == 'O') {
			currentState = state[prevState][3];
		} else if(input == 'G') {
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
