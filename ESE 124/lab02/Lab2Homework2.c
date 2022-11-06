#include <stdio.h>

int main () {

	unsigned int a;
	int p;
	unsigned int mask1;
	unsigned int mask2;


	printf("Type in a hex value:\n");
	scanf("%x", &a);
	
	printf("Type in a value for p (between 1 and 8):\n");
	scanf("%i", &p);
	
	
	mask1 = 0xff;
	mask1 = mask1>>(8-p);
	mask1 = mask1%256;
	printf("mask1 is %x\n", mask1);
	
	mask2 = 0xff;
	mask2 = mask2<<(8-p);
	mask2 = ~mask2;
	mask2 = mask2%256;
	printf("mask2 is %x\n", mask2);
	
	a = a|mask1;
	a = a&mask2;
	
	printf("Result is %x\n", a);
	
    return 0;
}
