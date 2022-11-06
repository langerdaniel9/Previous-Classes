#include <stdio.h>

int queue[100];
int queuePos = 0;
int numberAlive = 100;

void kill()
{
    printf("Kill %i\n", queue[queuePos]);
    int i;
    for (i = queuePos; i < numberAlive; i++)
    {
        queue[i] = queue[i + 1];
        queue[i + 1] = 0;
    }
    numberAlive--;
}

int main()
{
    int n, k;
    int i;

    printf("Enter the value for N:\n");
    scanf("%i", &n);
    printf("Enter the value for K:\n");
    scanf("%i", &k);

    for (i = 0; i < n; i++)
    {
        queue[i] = i + 1;
    }

    numberAlive = n;

    while (queue[1] != 0)
    {
        kill();
        queuePos += (k - 1);
        if (queuePos >= numberAlive)
        {
            queuePos = queuePos % numberAlive;
        }
    }

    printf("The one who stayed alive was %i", queue[0]);

    return 0;
}