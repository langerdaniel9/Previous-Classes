#include <stdio.h>

int main () {

	unsigned int a;
	unsigned int mask1 = 0x03;
	unsigned int mask2 = 0x3f;


	printf("Type in a hex value:\n");
	scanf("%x", &a);
	
	a = a|mask1;
	a = a&mask2;
	
	printf("Result is %x\n", a);
	
    return 0;
}
