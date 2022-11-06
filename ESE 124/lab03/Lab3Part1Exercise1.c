#include <stdio.h>

int main () {
	
	float posSum = 0;
	int posCount = 0;
	float negSum = 0;
	int negCount = 0;
	int nums = 0;
	
	for(nums; nums < 15; nums++) {
		float input;
		printf("Enter value %i:\n", nums+1);
		scanf("%f", &input);
		if(input < 0) {
			negSum += input;
			negCount++;
		} else {
			posSum += input;
			posCount++;
		}
	}

	float posAvg = posSum/(posCount);
	float negAvg = negSum/(negCount);
	
	if(posCount>1) {
		printf("Average of positives is %f.\n", posAvg);
	} else {
		printf("There are no positive values\n");
	}
	
	if(negCount>1) {
		printf("Average of negatives is %f.\n", negAvg);
	} else {
		printf("There are no neegative values\n");
	}
	
	
}
