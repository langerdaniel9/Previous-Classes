#include <stdio.h>
#include <math.h>

int main () {

	float x, n, answer = 0;
	int active = 1, i = 1;
	float smallestSum;
	int smallestSumIndex;
	float array[100];
	
	printf("Enter the value of x:\n");
	scanf("%f", &x);
	
	printf("Enter the accuracy:\n");
	scanf("%f", &n);
	
	printf("\n");
	
	while(active) {
		float numerator = -(pow(-1, i)) * pow((x-1), i);
		float denomonator = i;
		float value = numerator/denomonator;
		
		if(value > 0) {
			printf("+ %f", value);
		} else {
			printf(" %f ", value);
		}
		
		array[i] = value;

		answer += value;
		i++;
		if(i-1 == n) {
			active = 0;
		}
	}
	
	printf(" = %f", answer);
	printf("\nln(%f) is %f\n", x, answer);
	
	int repeat = n-3;
	int j;
	
	smallestSum = array[1] + array[2] + array[3];
	smallestSumIndex = 0;
	
	for(j = 0; j<=repeat; j++) {
		float currentSum = array[j+1] + array[j+2] + array[j+3];
		
		if(currentSum < smallestSum) {
			smallestSum = currentSum;
			smallestSumIndex = j;
		}
	}
	
	printf("smallest sum = %f\n", smallestSum);
	printf("consecutive terms = %f(term %i) %f(term %i) %f(term%i)", array[smallestSumIndex+1], smallestSumIndex+1, array[smallestSumIndex+2],smallestSumIndex+2, array[smallestSumIndex+3], smallestSumIndex+3);
	
	return 0;
}
