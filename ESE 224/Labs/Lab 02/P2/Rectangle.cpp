#include <math.h>
#include "Rectangle.h"
#include <iostream>
#include <iomanip>

Rectangle::Rectangle() { xCoord = 0, yCoord = 0, width = 1, height = 1; }

Rectangle::Rectangle(double initX, double initY, double initW, double initH) { xCoord = initX, yCoord = initY, width = initW, height = initH; }

double Rectangle::getX() { return xCoord; }

double Rectangle::getY() { return yCoord; }

double Rectangle::getWidth() { return width; }

double Rectangle::getHeight() { return height; }

double Rectangle::getArea() const { return abs(width * height); }

void Rectangle::makeMirrorX() { yCoord *= -1; }

void Rectangle::makeMirrorY() { xCoord *= -1; }

void Rectangle::makeMirrorOrigin() { xCoord *= -1, yCoord *= -1; }

bool Rectangle::operator>(const Rectangle &r2) const { return (getArea() > r2.getArea()); }

double Rectangle::operator-(const Rectangle &r2) const { return (getArea() - r2.getArea()); }

void Rectangle::print()
{
    // 2 digits kept after decimal point
    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::setw(10) << std::left << "The origin of the rectangle is (" << xCoord << ", " << yCoord << ")" << std::endl;
    std::cout << std::left << "The width is " << std::setw(10) << width << " and the height is " << height << std::endl;
}
