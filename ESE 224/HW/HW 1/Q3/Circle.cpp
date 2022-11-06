#include <iostream>
#include <iomanip>
#include "Circle.h"

using namespace std;

Circle::Circle(double initCenterX, double initCenterY, double initRadius)
{
    centerX = initCenterX;
    centerY = initCenterY;
    radius = initRadius;
}

double Circle::getCenterX() const { return centerX; }

double Circle::getCenterY() const { return centerY; }

double Circle::getRadius() const { return radius; }

void Circle::print()
{
    cout << fixed << setprecision(2) << "The circle is centered at (" << centerX << ", " << centerY << ")" << endl;

    cout << "The radius is" << setw(10) << radius << endl;
}

void Circle::operator*(double multiplier)
{
    radius *= multiplier;
}

bool Circle::operator==(const Circle &C2) const
{
    return ((centerX == C2.getCenterX()) && (centerY == C2.getCenterY()) && (radius == C2.getRadius()));
}
