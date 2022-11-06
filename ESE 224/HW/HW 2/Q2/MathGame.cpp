#include <iostream>
#include <cmath>

using namespace std;

void check(bool divide, double result)
{
    if (!divide)
    {
        int answer;
        cin >> answer;
        if (answer == result)
        {
            cout << "\nThat was correct" << endl
                 << endl;
        }
        else
        {
            cout << "\nThat was incorrect" << endl
                 << endl;
        }
    }
    else if (divide)
    {
        double answer;
        cin >> answer;
        if ((answer - result) < 0.1)
        {
            cout << "\nThat was correct" << endl
                 << endl;
        }
        else
        {
            cout << "\nThat was incorrect" << endl
                 << endl;
        }
    }
}

int main()
{
    srand(1521);
    bool loop = true;

    while (loop)
    {
        cout << "Input a number 1 - 5 to select a random problem or exit the game." << endl
             << "\t1 - Addition" << endl
             << "\t2 - Subtraction" << endl
             << "\t3 - Multiplication" << endl
             << "\t4 - Division" << endl
             << "\t5 - Exit" << endl;

        int choice;
        cin >> choice;

        int first = floor(rand() % 10 + 1);
        int second = floor(rand() % 10 + 1);
        int result;

        switch (choice)
        {
        case 1:
        {
            result = first + second;
            cout << first << " + " << second << " = ";
            check(false, result);
            break;
        }
        case 2:
        {
            result = first - second;
            cout << first << " - " << second << " = ";
            check(false, result);
            break;
        }
        case 3:
        {
            result = first * second;
            cout << first << " * " << second << " = ";
            check(false, result);
            break;
        }
        case 4:
        {
            double result = (double)first / second;
            cout << first << " / " << second << " = ";
            check(true, result);
            break;
        }
        case 5:
        {
            loop = false;
            cout << "Game finished" << endl;
            break;
        }
        default:
        {
            cout << "Invalid input" << endl
                 << endl;
            break;
        }
        }
    }
}