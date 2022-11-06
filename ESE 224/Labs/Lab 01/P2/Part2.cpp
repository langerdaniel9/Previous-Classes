#include "Rectangle.cpp"
#include <iostream>
using namespace std;

int main()
{
     cout << "Test default constructor: " << endl;
     Rectangle r1;
     cout << r1.toString();

     cout << "Test parmeterized constructor: " << endl;
     cout << "Enter the parameters (x, y, w, h): ";
     double x, y, w, h;
     cin >> x >> y >> w >> h;
     Rectangle r2(x, y, w, h);
     cout << r2.toString();

     cout << "Computer the area of the rectangle: ";
     double area = r2.getArea();
     cout << "The area is: " << area << endl;

     cout << "make mirror of x axis:" << endl;
     r2.makeMirrorX();
     cout << "Rectangle after x mirror:\n"
          << r2.toString();

     cout << "make mirror of y axis:" << endl;
     r2.makeMirrorY();
     cout << "Rectangle after y mirror:\n"
          << r2.toString();

     cout << "make mirror of origin:" << endl;
     r2.makeMirrorOrigin();
     cout << "Rectangle after origin mirror:\n"
          << r2.toString();

     return 0;
}
