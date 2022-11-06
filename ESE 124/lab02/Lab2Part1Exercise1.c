#include <stdio.h>

int main () {
	unsigned char ch;
	unsigned short sh;
	unsigned int in;
	unsigned long lo;
	
	printf("unsigned char is %lu bits long\n", sizeof(ch));
    printf("unsigned short is %lu bits long\n", sizeof(sh));
    printf("unsigned int is %lu bits long\n", sizeof(in));
    printf("unsigned long is %lu bits long", sizeof(lo));
    return 0;
}
