#include "Line.cpp"
#include <iostream>
using namespace std;

int main()
{
    double k, b;
    cout << "Enter the parameters for l1: " << endl;
    cin >> k >> b;
    Line l1(k, b);
    l1.print();

    cout << "Enter the parameters for l2: " << endl;
    cin >> k >> b;
    Line l2(k, b);
    l2.print();

    cout << "Line 1 is: " << endl;
    l1.print();

    cout << "Line 1 * 3.6 is " << endl;
    l1 * 3.6;
    l1.print();

    cout << "Line 1 + 2.32 is " << endl;
    l1 + 2.32;
    l1.print();

    cout << "l1 == l2 ? " << (l1 == l2) << endl;
    return 0;
}
