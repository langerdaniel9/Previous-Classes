#include "Point.h"
#include <math.h>

Point::Point()
{
    xCoord = 0;
    yCoord = 0;
}

Point::Point(double initX, double initY)
{
    xCoord = initX;
    yCoord = initY;
}

double Point::getX()
{
    return xCoord;
}

double Point::getY()
{
    return yCoord;
}

void Point::setX(double setX)
{
    xCoord = setX;
}

void Point::setY(double setY)
{
    yCoord = setY;
}

double Point::toOrigin()
{
    return sqrt(((xCoord) * (xCoord)) + ((yCoord) * (yCoord)));
}
