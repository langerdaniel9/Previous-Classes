#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"
#include "stack.c"

#define MAX 10

int main()
{
	int i = 0;
	char *queue[MAX];
	int queuePosition = 0;

	initializeQueue(queue, MAX);

	printf("Is empty? = %d\n", is_empty(queue));
	queuePosition = add(queue, "test", queuePosition);
	printf("Is empty? = %d\n", is_empty(queue));
	queuePosition = add(queue, "string2", queuePosition);
	queuePosition = add(queue, "string3", queuePosition);
	queuePosition = add(queue, "string4", queuePosition);
	queuePosition = add(queue, "string5", queuePosition);
	queuePosition = add(queue, "string6", queuePosition);
	queuePosition = add(queue, "string7", queuePosition);
	queuePosition = add(queue, "string8", queuePosition);
	queuePosition = add(queue, "string8", queuePosition);
	queuePosition = add(queue, "string8", queuePosition);
	printf("Is full? = %i\n", is_full(queue, MAX));

	_remove(queue, MAX);
	_remove(queue, MAX);
	_remove(queue, MAX);

	printQueue(queue, queuePosition);

	return 0;
}
