#include <stdio.h>

int main () {

	unsigned int a;
	unsigned int b = 0x0f;

	printf("Type in a hex value:\n");
	scanf("%x", &a);
	
	printf("Setting the least significant 4 bits of %x to 1111 gets %x\n", a, a|b);
	
    return 0;
}
