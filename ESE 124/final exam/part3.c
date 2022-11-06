#include <stdio.h>
#include <stdlib.h>

typedef struct rectangle
{
    int x1;
    int y1;
    int x2;
    int y2;
} rectangle;

rectangle array[20];
int arrayPosition = 0;

void store(int x1, int y1, int x2, int y2)
{
    array[arrayPosition].x1 = x1;
    array[arrayPosition].y1 = y1;
    array[arrayPosition].x2 = x2;
    array[arrayPosition].y2 = y2;
    arrayPosition++;
}

int checkOverlap(int a, int b)
{
    rectangle rect1 = array[a];
    rectangle rect2 = array[b];

    if (rect1.x2 <= rect2.x1 && rect1.y2 <= rect2.y1)
    {
        return 0;
    }
    else if (rect1.x1 >= rect2.x2 && rect1.y1 >= rect2.y2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void display(int i)
{
    printf("Lower Left = (%i, %i), Upper Right = (%i, %i)\n", array[i].x1, array[i].y1, array[i].x2, array[i].y2);
}

void _remove(int i)
{
    int k;
    for (k = i; k < arrayPosition - 1; k++)
    {
        array[k] = array[k + 1];
    }
    arrayPosition--;
}

int numberRectangles()
{
    return (arrayPosition - 1);
}

int main()
{
    FILE *input;
    if ((input = fopen("input3.txt", "r")) == NULL)
    {
        printf("error: input3.txt cannot be opened\n");
        exit(1);
    }

    int i = 0;
    int tempX1;
    int tempY1;
    int tempX2;
    int tempY2;
    while (fscanf(input, "%i %i %i %i", &tempX1, &tempY1, &tempX2, &tempY2) != EOF)
    {
        store(tempX1, tempY1, tempX2, tempY2);
    }
    printf("all rectangles = \n");
    for (i = 0; i < arrayPosition; i++)
    {
        display(i);
    }
    printf("\n\n");
    int j;
    for (i = 0; i < arrayPosition; i++)
    {
        int overlap = 0;
        for (j = 0; j < i; j++)
        {
            if (checkOverlap(i, j) == 1)
            {
                overlap = 1;
                break;
            }
        }
        for (j = i + 1; j < arrayPosition; j++)
        {
            if (checkOverlap(i, j) == 1)
            {
                overlap = 1;
                break;
            }
        }
        if (overlap == 0)
        {
            printf("No overlap: ");
            display(i);
        }
    }

    int overlaps[1000];
    for (i = 0; i < 1000; i++)
    {
        overlaps[i] = 0;
    }

    for (i = 0; i < arrayPosition; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (checkOverlap(i, j) == 1)
            {
                overlaps[i]++;
            }
        }
        for (j = i + 1; j < arrayPosition; j++)
        {
            if (checkOverlap(i, j) == 1)
            {
                overlaps[i]++;
            }
        }
    }

    int largest = 0;
    for (i = 0; i < arrayPosition + 1; i++)
    {
        if (overlaps[i] > overlaps[largest])
        {
            largest = i;
        }
    }
    printf("Rectangle with the largest number of overlaps is rectange %i, with %i overlaps\n", largest, overlaps[largest]);
}