#include "Point.cpp"
#include <iostream>
using namespace std;

int main()
{
    double x, y;
    cout << "Enter the xcoord and then ycoord for p1:" << endl;
    cin >> x >> y;
    Point p1(x, y);

    cout << "Enter the xcoord and then ycoord for p2:" << endl;
    cin >> x >> y;
    Point p2(x, y);

    p1.Print();

    cout << "The distance between the two points is: " << p1.Distance(p2) << endl;
    cout << "The distance between the two points is: " << (p1 - p2) << endl;
    cout << "Are the two points the same? The answer is " << p2.Equal(p1) << endl;
    cout << "Are the two points the same? The answer is " << (p1 == p2) << endl;

    return 0;
}
