#include <stdio.h>

//State 0 = none
//State 1 = A
//State 2 = AA
//State 3 = AAA
//State 4 = invalid

int main() {
	int prevState = 0;
	
	int state [5][2] = 
	{
		{1,0},
		{2,1},
		{3,2},
		{4,3},
		{4,4}
	};
	
	int output [5] = {0,0,0,1,0};
	
	while(1) {
		int currentState = 0;
		
		printf("Enter a character:\n");
		char input = getchar();
		getchar();
		
		if(input == 'A') {
			currentState = state[prevState][0];
		} else {
			currentState = state[prevState][1];
		}
		
		//printf("output[%i][%i]\n", prevState, currentState);
		printf("Output is %i\n", output[currentState]);
		prevState = currentState;
	}
	
	return 0;
}
