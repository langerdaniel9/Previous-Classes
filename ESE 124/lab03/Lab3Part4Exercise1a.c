#include <stdio.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////    1/(1-x)    ///////////////////////////////
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
		float value = pow(x, i);
		
		//printf("num = %f, den = %f, value = %f, i = %i\n", numerator, denomonator, value, i);
		
		answer += value;
		i++;
		if(fabs(value) < a) {
			active = 0;
		}
	}
	
	printf("Value of 1/(1-x) for %f is %f\n", x, answer);
	return 0;
}




