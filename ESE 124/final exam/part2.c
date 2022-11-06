#include <stdio.h>

// State 0 = invalid
// State 1 = g
// State 2 = ga
// State 3 = gag
// State 4 = gaga

int main()
{
    int occurances = 0;
    int prevState = 0;

    int state[5][3] =
        {
            {0, 1, 0},
            {0, 1, 2},
            {0, 3, 0},
            {0, 1, 4},
            {0, 3, 0},
        };

    int output[6] = {0, 0, 0, 0, 0, 1}; // each state and its corresponding output, state 0 outputs 0, state 1 outputs 0... state 5 outputs 1

    // This is essentially a Moore style FSM, so we always output the current state, thus reducing the number of columns in this table, if it was a mealeys FSM it would have to be the same size as the state array above

    while (1)
    {
        int currentState = 0; // reset state, same as inital prevState

        printf("Enter a character:\n");
        char input = getchar();
        getchar();

        if (input == 'g')
        {
            currentState = state[prevState][1]; // input C is column 1 of the table
        }
        else if (input == 'a')
        {
            currentState = state[prevState][2]; // input Y is column 2 of the table
        }
        else
        {
            currentState = state[prevState][0]; // invalid input is column 0 of the table
        }

        if (currentState == 4)
        {
            occurances++;
        }
        printf("%i occurances so far\n", occurances);
        prevState = currentState;
    }

    return 0;
}
