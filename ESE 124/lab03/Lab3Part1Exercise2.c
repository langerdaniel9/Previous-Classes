#include <stdio.h>
#include<math.h>

int main () {
	
	int n;
	unsigned int sum = 0;
	printf("Enter a value for n\n"); //max n is 9, 10 causes overflow
	scanf("%i", &n);
	
	int i;
	for(i = 1; i<n+1; i++) {
		sum += (pow(10, i)-1);
	}
	
	printf("The sum for %i terms is %i\n", n, sum);
	printf("Max for n is 9.\n");
	return 0;
}
