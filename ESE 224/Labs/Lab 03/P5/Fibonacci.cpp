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
    cout << "Enter the number of fibonacci's sequence to find (between 0 and 50)" << endl;
    int input;
    cin >> input;
    cout << "F(" << input << ") = " << Fibonacci(input) << endl;
    cout << "F(10) = " << Fibonacci(10) << endl;
    cout << "F(20) = " << Fibonacci(20) << endl;
    cout << "F(30) = " << Fibonacci(30) << endl;
    cout << "F(40) = " << Fibonacci(40) << endl;
    cout << "F(50) = " << Fibonacci(50) << endl;
}