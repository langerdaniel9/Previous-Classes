#include <stdio.h>
#include <stdbool.h>
// initialize maze, sideways cause C reads it row then column instead of column then row
char maze[8][8] = {
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', ' ', ' '},
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', ' ', '*', ' ', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*'}};

typedef struct tuple
{
    int x;
    int y;
} tuple;

tuple queue[100];
int queuePos = 0;
int minQueuePos = 0;
bool possibleMoves[4] = {false, false, false, false}; // up, right, down, left

tuple currentPosition;
tuple nextPosition;

// finds squares that it can move to
int checkSurroundings(int x, int y)
{
    // check if up is a wall
    if (maze[x][y - 1] == '*')
    {
        possibleMoves[0] = false;
    }
    else
    {
        possibleMoves[0] = true;
    }
    // check is right is a wall
    if (maze[x + 1][y] == '*')
    {
        possibleMoves[1] = false;
    }
    else
    {
        possibleMoves[1] = true;
    }
    // check is down is a wall
    if (maze[x][y + 1] == '*')
    {
        possibleMoves[2] = false;
    }
    else
    {
        possibleMoves[2] = true;
    }
    // check is left is a wall
    if (maze[x - 1][y] == '*')
    {
        possibleMoves[3] = false;
    }
    else
    {
        possibleMoves[3] = true;
    }

    if (possibleMoves[0] == false && possibleMoves[1] == false && possibleMoves[2] == false && possibleMoves[3] == false)
    {
        printf("There are no possible moves");
        return 3;
    }
}

// checks if you have been at a specific square already
int checkIfNew()
{
    int i;

    if (queuePos > 0)
    {
        for (i = queuePos - 1; i >= minQueuePos; i--)
        {
            if (queue[i].x == nextPosition.x && queue[i].y == nextPosition.y)
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int i, j;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("%c", maze[j][i]); // prints sideways because humans and C read the array differently apparently
        }
        printf("\n");
    }

    printf("Enter the starting position in the format x,y:\n");
    scanf("%i,%i", &currentPosition.x, &currentPosition.y);

    // checks if you are starting in a wall
    if (maze[currentPosition.x][currentPosition.y] != ' ')
    {
        printf("Invalid starting position.\n");
        return 1;
    }

    queue[queuePos].x = currentPosition.x;
    queue[queuePos].y = currentPosition.y;
    queuePos++;

    // while you arent on the outer ring of the 8x8 maze (AKA at the exit of the maze)
    while (currentPosition.x != 0 || currentPosition.x != 7 || currentPosition.y != 0 || currentPosition.y != 7)
    {
        if (currentPosition.x == 0 || currentPosition.x == 7 || currentPosition.y == 0 || currentPosition.y == 7)
        {
            break;
        }

        if (queuePos > 40)
        {
            printf("Could not find a way out\n");
            return 2;
        }

        ;

        if (checkSurroundings(currentPosition.x, currentPosition.y) == 3)
        {
            return 3;
        }

        int moveToQueue2 = 0;

        if (possibleMoves[0] == true)
        {
            moveToQueue2++;
            // printf("0-");
            nextPosition.x = currentPosition.x;
            nextPosition.y = currentPosition.y - 1;
            // printf("next position = (%i, %i)\n", nextPosition.x, nextPosition.y);
            if (checkIfNew())
            {
                moveToQueue2--;
                currentPosition.x = nextPosition.x;
                currentPosition.y = nextPosition.y;
                queue[queuePos].x = currentPosition.x;
                queue[queuePos].y = currentPosition.y;
                queuePos++;
                continue;
            }
        }
        if (possibleMoves[1] == true)
        {
            moveToQueue2++;
            // printf("1-");
            nextPosition.x = currentPosition.x + 1;
            nextPosition.y = currentPosition.y;
            // printf("next position = (%i, %i)\n", nextPosition.x, nextPosition.y);

            if (checkIfNew())
            {
                moveToQueue2--;
                currentPosition.x = nextPosition.x;
                currentPosition.y = nextPosition.y;
                queue[queuePos].x = currentPosition.x;
                queue[queuePos].y = currentPosition.y;
                queuePos++;
                continue;
            }
        }
        if (possibleMoves[2] == true)
        {
            moveToQueue2++;
            // printf("2-");
            nextPosition.x = currentPosition.x;
            nextPosition.y = currentPosition.y + 1;
            // printf("next position = (%i, %i)\n", nextPosition.x, nextPosition.y);

            if (checkIfNew())
            {
                moveToQueue2--;
                currentPosition.x = nextPosition.x;
                currentPosition.y = nextPosition.y;
                queue[queuePos].x = currentPosition.x;
                queue[queuePos].y = currentPosition.y;
                queuePos++;
                continue;
            }
        }
        if (possibleMoves[3] == true)
        {
            moveToQueue2++;
            // printf("3-");
            nextPosition.x = currentPosition.x - 1;
            nextPosition.y = currentPosition.y;
            // printf("next position = (%i, %i)\n", nextPosition.x, nextPosition.y);

            if (checkIfNew())
            {
                moveToQueue2--;
                currentPosition.x = nextPosition.x;
                currentPosition.y = nextPosition.y;
                queue[queuePos].x = currentPosition.x;
                queue[queuePos].y = currentPosition.y;
                queuePos++;
                continue;
            }
        }
        if (moveToQueue2 != 0)
        {
            minQueuePos = queuePos - 1;
        }
    }

    // print queue

    printf("The path to exit is:\n");

    int startingQueuePos = 0;
    for (i = 0; i < queuePos; i++)
    {
        if (queue[i].x == queue[0].x && queue[i].y == queue[0].y)
        {
            startingQueuePos = i;
        }
    }

    for (i = startingQueuePos; i < queuePos; i++)
    {
        printf("(%i, %i)", queue[i].x, queue[i].y);
        if (i != queuePos - 1)
        {
            printf(" -> ");
        }
    }
    printf("\n");

    return 0;
}