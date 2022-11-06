#include "Point.h"
#include <math.h>
#include <iostream>

Point::Point() { xCoord = 0, yCoord = 0; }

Point::Point(double initX, double initY) { xCoord = initX, yCoord = initY; }

double Point::getX() { return xCoord; }

double Point::getY() { return yCoord; }

void Point::setX(double setX) { xCoord = setX; }

void Point::setY(double setY) { yCoord = setY; }

double Point::toOrigin() { return sqrt(((xCoord) * (xCoord)) + ((yCoord) * (yCoord))); }

double Point::Distance(const Point &p2) const
{
    double x1 = xCoord, y1 = yCoord, x2 = p2.xCoord, y2 = p2.yCoord;
    return sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));
}

double Point::operator-(const Point &p2)
{
    double x1 = xCoord, y1 = yCoord, x2 = p2.xCoord, y2 = p2.yCoord;
    return sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));
}

bool Point::Equal(const Point &p2) const { return ((xCoord == p2.xCoord) && (yCoord == p2.yCoord)); }

bool Point::operator==(const Point &p2) const { return ((xCoord == p2.xCoord) && (yCoord == p2.yCoord)); }

void Point::Print()
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    std::cout << "The point is (" << xCoord << ", " << yCoord << ")" << std::endl;
}
