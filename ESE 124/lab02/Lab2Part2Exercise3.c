#include <stdio.h>
#include <string.h>

int main () {

	unsigned int a, b;
	int p, n;

	//unsigned int a = 0x1f;
	//unsigned int b = 0xc3;
	//int p = 5;
	//int n = 2;

	int var;
	int dif = 0;
	int mask1;
	int mask1a = 0xff;
	int mask1b = 0xff;
	int mask2 = 0xff;


	printf("Enter the first hex value:\n");
	scanf("%x", &a);
	
	printf("Enter the first hex value:\n");
	scanf("%x", &b);

	printf("Enter n:\n");
	scanf("%i", &n);
	
	printf("Enter p:\n");
	scanf("%i", &p);
	
/*

	while(p>8 || n>8) {
		printf("Integers are greater than 8, try again.");
		
		printf("Enter n:\n");
		scanf("%i", &n);
		
		printf("Enter p:\n");
		scanf("%i", &p);
	}		
*/
	
	var = 8-(p-1);
	if(n>var){
		dif = abs(var-n);
		n=var;
	}

	mask1a = mask1a >> (p-1);
	//printf("Mask 1a is %x\n", mask1a);	
	mask1b = mask1b << abs(p-(9-n));
	mask1b = (mask1b % 256);
	//printf("Mask 1b is %x\n", mask1b);	
	mask1a = mask1a & mask1b;
	mask1a = ~mask1a;
	mask1 = mask1a & 0xff; //not sure if needed or even works

	//printf("Mask 1 is %x\n", mask1);

	mask2 = mask2 << (n);
	mask2 = ~mask2;
	mask2 = mask2 % 256; //not sure if needed or even works

	//printf("Mask 2 is %x\n", mask2);

	a = a&mask1;
	//printf("A is %x\n", a);
	b = b>>dif;
	//printf("diff is %i\n", dif);
	b = b&mask2;
	//printf("B is %x\n", b);

	/*if(p>n) {
		b = b<<(9-(n+p));
	} else {
		b = b>>(p-(9-n));
	}	*/

	b = b<<(9-(n+p)+dif);

	//printf("B is %x\n", b);
	
	printf("Result is %x\n", a|b);
	
    return 0;
}
