#ifndef STACK
#define STACK

void clear(char *queue[], int SIZE);

int is_empty(char *queue[]);

int is_full(char *queue[], int SIZE);

int add(char *queue[], char *string, int element);

void _remove(char *queue[], int max);

void printQueue(char *queue[], int queuePosition);

void initializeQueue(char *queue[], int max);

#endif