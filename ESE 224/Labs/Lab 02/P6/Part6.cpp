#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool checkIfPalindrome(int number)
{
    string num = to_string(number);

    for (int i = 0, j = num.length() - 1; i < j; i++, j--)
    {
        if (num.at(i) != num.at(j))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    bool cont = true;
    while (cont)
    {
        int input;
        cout << "Enter a number to check if it is a palindrome: " << endl;
        cin >> input;

        if (cin.fail()) // If input is not an integer, check for error and recover
        {
            cout << "Invalid input" << endl
                 << endl;
            cin.clear();
            string temp;
            getline(cin, temp);
            continue;
        }

        // Check if the input is -1 to end execution
        if (input == -1)
        {
            cont = false;
            break;
        }

        // pass to checkIfPalindrome function and give output.
        bool returns = checkIfPalindrome(input);

        cout << ((returns) ? ("That number was a palindrome")
                           : ("That number was not a palindrome"))
             << endl
             << endl;
    }

    return 0;
}
