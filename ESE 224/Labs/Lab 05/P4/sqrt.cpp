#include <iostream>

using namespace std;

double sqrt(double in)
{
    double temp = 0, root = in / 2, num = in;

    while (root != temp)
    {
        temp = root;
        root = ((num / temp) + temp) / 2;
    }

    return root;
}

int main()
{
    cout << "What number to find the root of?" << endl;
    double num;
    cin >> num;
    double root = sqrt(num);

    cout << "The result is " << root << endl;
}