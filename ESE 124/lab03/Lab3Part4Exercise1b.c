#include <stdio.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////    sin(x)     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int main () {

	float x, a, answer = 0;
	int active = 1, i = 0;
	
	printf("Enter the value of x:\n");
	scanf("%f", &x);
	
	/*while(x<-1 || x>1) {
		printf("x outside of range, try again:\n");
		scanf("%f", &x);
	}*/
	
	printf("Enter the accuracy:\n");
	scanf("%f", &a);

	while(active) {
		float numerator = pow(-1, i) * pow(x, 2*i+1);
		float denomonator = factorial(2*i+1);
		float value = numerator/denomonator;
		
		//printf("num = %f, den = %f, value = %f, i = %i\n", numerator, denomonator, value, i);
		
		answer += value;
		i++;
		if(fabs(value) < a) {
			active = 0;
		}
	}
	
	printf("Sin of %f is %f", x, answer);
	return 0;
}

int factorial(integer) {
	int value = integer;
	int sum = 1;
	while (value > 0) {
		sum *= value;
		value--;
	}
	return sum;
}



