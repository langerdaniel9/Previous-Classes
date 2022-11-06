#include <stdio.h>

int main () {
	
	float small, small2, small3, largest, input;
	int turns = 0, first = 1, n;
	
	printf("Enter the max number of turns where the largest can stay the same:\n");
	scanf("%i", &n);

	
	while(turns<n) {
		
		printf("Enter a number:\n");
		scanf("%f", &input);
		
		if(first == 1) { 
			
			small = input;
			largest = input;
			turns = 0;
			first++;
			
		} else if(first == 2) { 
			
			if(input < small) {
				small2 = small;
				small = input;
				turns++;
			} else if(input == small) {
				small2 = input;
				turns++;
			} else if(input > small) {
				small2 = input;
				largest = input;
				turns = 0;
			}
			first++;
			
		} else if(first == 3) {
			
			if(input < small) {
				small3 = small2;
				small2 = small;
				small = input;
				turns++;
			} else if (input < small2) {
				small3 = small2;
				small2 = input;
				turns++;
			} else {
				small3 = input;
				largest = input;
				turns = 0;
			}
			first++;
			
		} else if (first >= 4) {
			
			if(input > largest) {
				turns = 0;
			} else {
				turns++;
			}
			
			if(input<small) {
				small3 = small2;
				small2 = small;
				small = input;
			} else if (input < small2) {
				small3 = small2;
				small2 = input;
			} else if (input < small3) {
				small3 = input;
			}
		}
		printf("Smallest is %f, second smallest is %f, third smallest is %f", small, small2, small3);
		
	}
	
	printf("Largest hasn't changed for %i turn(s), program has ended.", n);
	return 0;
	
}
