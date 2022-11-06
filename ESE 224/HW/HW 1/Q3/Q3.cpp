#include "Circle.cpp"
#include <iostream>

using namespace std;

int main()
{
    double x, y, r;
    cout << "Enter the parameters for circle 1: (x, y, radius)" << endl;
    cin >> x >> y >> r;
    Circle c1(x, y, r);

    cout << "Enter the parameters for circle 2: (x, y, radius)" << endl;
    cin >> x >> y >> r;
    Circle c2(x, y, r);

    cout << "Circle 1 is: " << endl;
    c1.print();
    cout << "Circle 2 is: " << endl;
    c2.print();

    cout << "Circles are equivalent? " << (c1 == c2) << endl;

    cout << "Circle 2 * 3.4" << endl;
    c2 * 3.4;
    c2.print();
}