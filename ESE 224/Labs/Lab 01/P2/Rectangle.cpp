#include <string>
#include <math.h>
#include "Rectangle.h"

Rectangle::Rectangle()
{
    xCoord = 0;
    yCoord = 0;
    width = 1;
    height = 1;
}

Rectangle::Rectangle(double initX, double initY, double initW, double initH)
{
    xCoord = initX;
    yCoord = initY;
    width = initW;
    height = initH;
}

double Rectangle::getX()
{
    return xCoord;
}

double Rectangle::getY()
{
    return yCoord;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::getArea()
{
    return abs(width * height);
}

void Rectangle::makeMirrorX()
{
    yCoord *= -1;
}

void Rectangle::makeMirrorY()
{
    xCoord *= -1;
}

void Rectangle::makeMirrorOrigin()
{
    xCoord *= -1;
    yCoord *= -1;
}

std::string Rectangle::toString()
{
    return "The origin is (" + std::to_string(xCoord) + ", " + std::to_string(yCoord) + "), the width is: " + std::to_string(width) + ", the height is: " + std::to_string(height) + ".\n";
}
