#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string reverse(string toReverse)
{
    string toReturn = "";

    int length = toReverse.length();
    for (int i = length - 1; i >= 0; i--)
    {
        toReturn += toReverse[i];
    }
    return toReturn;
}

int main()
{
    ifstream input("input.txt");
    ofstream output("newfile.txt");
    if (input.fail() || output.fail())
    {
        cerr << "Error opening file";
        exit(1);
    }

    while (true)
    {
        string word;
        input >> word;
        if (input.fail())
        {
            break;
        }
        if (word == reverse(word))
        {
            output << word << endl;
        }
        else
        {
            cout << word << endl;
        }
    }
}