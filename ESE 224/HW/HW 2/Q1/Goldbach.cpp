#include <iostream>
#include <cctype>

using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    for (int i = 2; i < (n / 2); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void printGoldbach(int number)
{
    bool has = false;
    for (int firstPrime = 3; firstPrime <= number / 2; firstPrime++)
    {
        int secondPrime = number - firstPrime;
        if (isPrime(secondPrime))
        {
            has = true;
            cout << firstPrime << " + " << secondPrime << endl;
        }
    }

    if (!has)
    {
        cout << "No Goldbach representation exists" << endl;
    }
}

int main()
{
    cout << "Enter a number to get the Goldbach representation:" << endl;
    int input;
    cin >> input;

    if (cin.fail() || (input >= 50000 && input <= 4) || ((input % 2) != 0))
    {
        cout << "Invalid input, try again" << endl;
        exit(1);
    }

    printGoldbach(input);
}