#include <iostream>

using namespace std;

int main()
{
    char input;
    cout << "Enter a letter grade (A, B, C, D, F): " << endl;
    cin >> input;
    toupper(input); // Makes checking if valid easier and reduces cases for switch

    // Checks if input is valid
    while (input != 'A' && input != 'B' && input != 'C' && input != 'D' && input != 'F')
    {
        cout << "Invalid input, enter a valid letter grade (A, B, C, D, F): " << endl;
        cin >> input;
    }

    // Switch to decide output
    switch (input)
    {
    case 'A':
        cout << "Letter grade A is equivalent to a 4.00";
        break;

    case 'B':
        cout << "Letter grade B is equivalent to a 3.00";
        break;

    case 'C':
        cout << "Letter grade C is equivalent to a 2.00";
        break;

    case 'D':
        cout << "Letter grade D is equivalent to a 1.00";
        break;

    case 'F':
        cout << "Letter grade F is equivalent to a 0.00";
        break;
    }
}