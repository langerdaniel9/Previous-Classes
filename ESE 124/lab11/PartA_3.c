#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double * returnPointer(char * line) {
	double array[30];
	char *token;
	int i;
	int doubleCounter = 0;

	//find the number of doubles in the users input
	for(i=0; i<100; i++) {
		if(line[i] == '.') {
			doubleCounter++;
		}
	}

	//separate the users input into individual doubles and put them into the array
   token = strtok(line, " ");
   char * dontCare;
   i=0;
   
   while( token != NULL ) {
		array[i] = strtod(token, &dontCare);
		i++;
      	token = strtok(NULL, " ");
   }

	//check for the largest
	int largest = 0;
	for(i=1; i<doubleCounter; i++) {
		if (array[i] > array[largest]) {
			largest = i;
		}
	}

	//printf("largest = %.1f", largest);
	double *p;
	p = &array[largest];
	return p;
}

int main(void)
{
	char line[100];

	//get the users input
	printf("Input the array of doubles:\n");
	fgets(line, 100, stdin);

	//calls function and prints value
	double * pointer = returnPointer(line);
	printf("return value is %.1f, address is %p", *pointer, pointer);

	return 0;
}
