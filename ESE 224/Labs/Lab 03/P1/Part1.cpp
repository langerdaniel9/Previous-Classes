#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("input.dat");
    if (fin.fail())
    {
        cerr << "Error opening input file!";
        exit(1);
    }

    ofstream fout("output.dat");
    if (fout.fail())
    {
        cerr << "Error opening output file!";
        exit(1);
    }

    string content;
    fin >> content;
    fout << content;

    fin.close();
    fout.close();
    return 0;
}