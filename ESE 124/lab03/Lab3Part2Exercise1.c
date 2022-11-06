#include <stdio.h>

int main () {
	
	float last;
	int posCount = 0;
	int negCount = 0;
	int zeroCount = 0;
	
	while(1) {
		float input;
		printf("Enter a number:\n");
		scanf("%f", &input);
		
		if(input == last) {
			if(input>0) {
				posCount ++;
				last = input;
			} else if (input<0) {
				negCount ++;
				last=input;
			} else if (input == 0) {
				zeroCount ++;
				last = input;
			}
			printf("Pos = %i | Neg = %i | Zero = %i\n", posCount, negCount, zeroCount);
			printf("Program Terminated\n");
			return 0;
		}
		
		if(input>0) {
			posCount ++;
			last = input;
		} else if (input<0) {
			negCount ++;
			last=input;
		} else if (input == 0) {
			zeroCount ++;
			last = input;
		}
		printf("Pos = %i | Neg = %i | Zero = %i\n", posCount, negCount, zeroCount);
	}
	
}
