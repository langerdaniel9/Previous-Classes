#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cout << "Enter a string" << endl;
    cin >> input;

    int longest = 0;

    // single digits
    for (int i = 0; i < input.length(); i++)
    {
        int left = i, right = i;
        int length = -1;
        while ((left >= 0) && (right < input.length()))
        {
            if (input[left] == input[right])
            {
                length += 2;
                left--;
                right++;
            }
            else
            {
                break;
            }

            if (length > longest)
            {
                longest = length;
            }
        }
    }

    // digit pairs
    for (int i = 0; i < input.length() - 1; i++)
    {
        int left = i, right = i + 1;
        int length = 0;
        while ((left >= 0) && (right < input.length()))
        {
            if (input[left] == input[right])
            {
                length += 2;
                left--;
                right++;
            }
            else
            {
                break;
            }

            if (length > longest)
            {
                longest = length;
            }
        }
    }

    cout << "Longest is " << longest << endl;
}