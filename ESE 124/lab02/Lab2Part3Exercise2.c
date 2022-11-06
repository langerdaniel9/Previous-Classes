#include <stdio.h>

int main () {

	unsigned int a, b; //unsigned char doesnt work
	int p, n;
	
	int mask = 0xff;

	char operation;

	printf("Enter the first hex value:\n");
	scanf("%x", &a);

	printf("Enter n. Make sure it is less than 8:\n");
	scanf("%i", &n);
	
	printf("Enter p. Make sure it is less than 8:\n");
	scanf("%i", &p);
	fflush(stdin);
	
	while(1){
		printf("Enter a command (S, R, F, D, I).\n"); // or E to end
		fflush(stdin);
		scanf("%c", &operation);	
		
		switch(operation) {
			case 'S': {

				int var = 8-(p-1);
				if(n>var){
					int dif = abs(var-n);
					n=var;
				}
				
				int mask2 = mask;
				mask2 = mask2>>(p-1);
				
				int mask3 = mask;
				mask3 = mask3 << abs(p-(9-n));
				
				int mask4 = mask2&mask3;
				
				printf("The result is %x\n\n", a|mask4);
				
				break;
			}
			
			case 'R': {
				
				int var = 8-(p-1);
				if(n>var){
					int dif = abs(var-n);
					n=var;
				}
				
				int mask2 = mask;
				mask2 = mask2>>(p-1);
				
				int mask3 = mask;
				mask3 = mask3 << abs(p-(9-n));
				
				int mask4 = mask2&mask3;
				mask4 = ~mask4;
				
				printf("The result is %x\n\n", a&mask4);
				
				break;
			}
			
			case 'F': {
				
				int var = 8-(p-1);
				if(n>var){
					int dif = abs(var-n);
					n=var;
				}
				
				int mask2a = mask;
				mask2a = mask2a>>(p-1);
				int mask2b = mask;
				mask2b = mask2b << abs(p-(9-n));
				int mask2 = mask2a&mask2b;
				int mask3 = a&mask2;
				mask3 = ~mask3;
				mask3 = mask3 & mask2;
				mask2 = ~mask2;
				mask2 = mask2&a;
								
				printf("The result is %x\n\n", mask2|mask3);
				
				break;
			}
			
			case 'D': {
				printf("The value of %x is %i\n", a, a);
				break;
			}
			
			case 'I': {
				printf("Enter the new hex value:\n");
				scanf("%x", &b);
				break;
			}
			
			case 'E': {
				return 0;
			}
		}
		
	}	

}
