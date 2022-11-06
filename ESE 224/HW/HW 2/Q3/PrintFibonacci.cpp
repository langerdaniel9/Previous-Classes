#include <iostream>

using namespace std;

long long int Fibonacci(int input)
{
    long long int prev = 0, current = 1;
    for (int i = 0; i < input; i++)
    {
        long long int tempPrev = prev;
        prev = current;
        current += tempPrev;
    }
    return prev;
}

int main()
{
    cout << "Which function to use (1: single line | 2: lower left triangle | 3: upper left triangle): ";
    int fcn;
    cin >> fcn;
    if (cin.fail() || (fcn != 1 && fcn != 2 && fcn != 3))
    {
        cout << "Invalid input try again" << endl;
        exit(1);
    }

    cout << "What value for n: ";
    int n;
    cin >> n;
    cout << endl;
    if (cin.fail())
    {
        cout << "Invalid input try again" << endl;
        exit(1);
    }

    switch (fcn)
    {
    case 1:
    {
        for (int i = 0; i < n; i++)
        {
            cout << Fibonacci(i) << "\t";
        }
        break;
    }
    case 2:
    {
        int current = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << Fibonacci(current) << "\t";
                current++;
            }
            cout << endl;
        }
        break;
    }
    case 3:
    {
        int current = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << Fibonacci(current) << "\t";
                current++;
            }
            cout << endl;
        }
        break;
    }
    }
}