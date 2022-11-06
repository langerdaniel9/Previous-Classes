#include <stdio.h>

int main () {

	unsigned char a;
	int p, n;

	printf("Type in a hex value:\n");
	scanf("%x", &a);
	
	printf("Type in an integer value for p that is less than 8:\n");
	scanf("%i", &p);
	
	printf("Type in an integer value for n that is less than 8:\n");
	scanf("%i", &n);
	
	if(p>8 || n>8) {
		printf("Integers are greater than 8, try again.");
		return 0;
	}		

	unsigned char mask = a;
	mask = mask<<(7-p);
	mask = mask>>(8-n);
	
	
	printf("Result of %x is %x\n", a, mask);
	
    return 0;
}
