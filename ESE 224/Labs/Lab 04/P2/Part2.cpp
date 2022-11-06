#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void capitalize(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (islower(s[i]))
        {
            char temp = s[i];
            s[i] = toupper(temp);
        }
    }
}

int main()
{
    bool loop = true;
    while (loop)
    {
        string input;
        cout << "Enter a string (q to quit): ";
        getline(cin, input);
        if (input == "q")
        {
            loop = false;
            break;
        }
        capitalize(input);
        cout << input << endl;
    }
}