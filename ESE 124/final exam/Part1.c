#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float array[5][12];
float monthlyCost[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void readFile()
{

    FILE *input;
    if ((input = fopen("input1.txt", "r")) == NULL)
    {
        printf("error: input1.txt cannot be opened\n");
        exit(1);
    }
    int i;
    for (i = 0; i < 5; i++)
    {
        fscanf(input, "%f %f %f %f %f %f %f %f %f %f %f %f", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5], &array[i][6], &array[i][7], &array[i][8], &array[i][9], &array[i][10], &array[i][11]);
    }
}

void printArray()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            printf("%.2f ", array[i][j]);
        }
        printf("\n");
    }
}

void findExpensiveMonth()
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            monthlyCost[j] += array[i][j];
        }
    }

    int highest = 0;
    for (i = 1; i < 12; i++)
    {
        if (monthlyCost[i] > monthlyCost[highest])
        {
            highest = i;
        }
    }

    printf("highest month number is = %i\n", highest);
}

void findExpensiveItem()
{
    int i, j;
    float itemCost[] = {0, 0, 0, 0, 0};

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 5; j++)
        {
            itemCost[j] += array[j][i];
        }
    }

    int highest = 0;
    for (i = 1; i < 5; i++)
    {
        if (itemCost[i] > itemCost[highest])
        {
            highest = i;
        }
    }

    printf("highest item number is = %i\n", highest);
}

void findMontlyAverage()
{
    int i, j;
    float averageCost[12];

    for (i = 0; i < 12; i++)
    {
        averageCost[i] = monthlyCost[i] / 5;
    }

    for (i = 0; i < 12; i++)
    {
        printf("Average for month %i is %.2f\n", i, averageCost[i]);
    }
}

void sortByMonthlyPrice()
{
    typedef struct thing
    {
        int month;
        float total;
    } thing;

    int i, j;
    thing monthTotals[12];
    for (i = 0; i < 12; i++)
    {
        monthTotals[i].total = monthlyCost[i];
        monthTotals[i].month = i;
    }

    for (i = 0; i < 12; i++)
    {
        // printf("%i, %f\n", monthTotals[i].month, monthTotals[i].total);
    }

    bool sorted = false;
    thing temp;

    while (!sorted)
    {
        sorted = true;
        for (i = 0; i < 12 - 1; i++)
        {
            if ((monthTotals[i].total < monthTotals[i + 1].total))
            {
                temp = monthTotals[i];
                monthTotals[i] = monthTotals[i + 1];
                monthTotals[i + 1] = temp;
                sorted = false;
            }
        }
    }

    for (i = 0; i < 12; i++)
    {
        printf("Month %i total is %.2f\n", monthTotals[i].month, monthTotals[i].total);
    }
}

void printOutputFile()
{
    FILE *output;
    if ((output = fopen("output1.txt", "w")) == NULL)
    {
        printf("error: output1.txt cannot be created\n");
        exit(1);
    }

    typedef struct thing
    {
        int month;
        float total;
    } thing;

    int i, j;
    thing monthTotals[12];
    for (i = 0; i < 12; i++)
    {
        monthTotals[i].total = monthlyCost[i];
        monthTotals[i].month = i;
    }

    bool sorted = false;
    thing temp;

    while (!sorted)
    {
        sorted = true;
        for (i = 0; i < 12 - 1; i++)
        {
            if ((monthTotals[i].total < monthTotals[i + 1].total))
            {
                temp = monthTotals[i];
                monthTotals[i] = monthTotals[i + 1];
                monthTotals[i + 1] = temp;
                sorted = false;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            fprintf(output, "%.2f ", array[i][monthTotals[j].month]);
        }
        fprintf(output, "\n");
    }
}

void createOneDimArray()
{
    float *array2 = (float *)malloc(12 * sizeof(float));

    int i, j;

    for (i = 0; i < 12; i++)
    {
        int largest = 0;

        for (j = 0; j < 5; j++)
        {
            if (array[largest][i] < array[j][i])
            {
                largest = j;
            }
        }
        array2[i] = array[largest][i];
    }

    for (i = 0; i < 12; i++)
    {
        printf("%.2f ", array2[i]);
    }
}

int main()
{

    readFile();
    // printArray();
    // findExpensiveMonth();
    // findExpensiveItem();
    // findMontlyAverage();
    // sortByMonthlyPrice();
    // printOutputFile();
    createOneDimArray();
}