#include <fstream>
#include <iostream>

using namespace std;

void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main()
{
    double a, b;
    ifstream datain;
    datain.open("input.dat");
    if (datain.fail())
    {
        cerr << "File cannot be opened.";
        exit(1);
    }
    ofstream dataout;
    dataout.open("output.dat");
    if (dataout.fail())
    {
        cerr << "File cannot be opened";
        exit(1);
    }
    while (!datain.eof())
    {
        datain >> a >> b;
        swap(a, b);
        dataout << a << " " << b << endl;
    }
}