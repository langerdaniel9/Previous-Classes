#include <stdio.h>

void clear(char *queue[], int SIZE)
{
    int i;
    for (i = 0; i <= SIZE; i++)
    {
        queue[i] = NULL;
    }
}

int is_empty(char *queue[])
{
    if (queue[0] == NULL)
    {
        return 1; // is empty
    }
    else
    {
        return 0; // isnt empty
    }
}

int is_full(char *queue[], int SIZE)
{
    if (queue[SIZE - 1] != NULL)
    {
        return 1; // is full
    }
    else
    {
        return 0; // isnt full
    }
}

int add(char *queue[], char *string, int element)
{
    queue[element] = string;
    return element + 1;
}

void _remove(char *queue[], int max)
{
    int i;
    for (i = 0; i < max - 1; i++)
    {
        queue[i] = queue[i + 1];
    }
    queue[max - 1] = NULL;
}

void printQueue(char *queue[], int queuePosition)
{
    int i;
    for (i = 0; i < queuePosition; i++)
    {
        if (queue[i] != NULL)
        {
            printf("%s\n", queue[i]);
        }
    }
}

void initializeQueue(char *queue[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        queue[i] = NULL;
    }
}
