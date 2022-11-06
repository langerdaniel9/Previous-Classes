#include <stdio.h>

int main () {

	unsigned int a = 0x12;
	unsigned int b = 0xda;
	unsigned int c = 0x3b;
	unsigned int d = 0xbe;
	unsigned int hex;

	printf("Type in a hex value:\n");
	scanf("%x", &hex);

	printf("\nAs hex, a is %x, b is %x, c is %x, d is %x\n", a, b, c, d);
	printf("As decimal, a is %d, b is %d, c is %d, d is %d\n", a, b, c, d);
	printf("As character, a is %c, b is %c, c is %c, d is %c\n\n", a, b, c, d);
	
	
	printf("Bitwise and between %x and %x is %x\n", a, b, a&b);
	printf("Bitwise or between %x and %x is %x\n", a, b, a|b);
	printf("Bitwise exclusive or between %x and %x is %x\n", a, b, a^b);

	printf("Bitwise and between %x and %x is %x\n", c, d, c&d);
	printf("Bitwise or between %x and %x is %x\n", c, d, c|d);
	printf("Bitwise exclusive or between %x and %x is %x\n", c, d, c^d);

    return 0;
}
