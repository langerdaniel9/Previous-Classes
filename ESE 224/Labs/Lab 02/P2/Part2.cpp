#include "Rectangle.cpp"
#include <iostream>
using namespace std;

int main()
{
    double x, y, w, h;
    cout << "Enter the parameters (x, y, w, h): ";
    cin >> x >> y >> w >> h;
    Rectangle r1(x, y, w, h);

    cout << "Enter the parameters (x, y, w, h): ";
    cin >> x >> y >> w >> h;
    Rectangle r2(x, y, w, h);

    cout << "First rectangle larger than the second rectangle is: " << (r1 > r2) << endl;

    cout << "Difference in area is: " << (r1 - r2) << endl;

    cout << "First rectangle was:" << endl;
    r1.print();

    cout << "Second rectangle was:" << endl;
    r2.print();

    return 0;
}
