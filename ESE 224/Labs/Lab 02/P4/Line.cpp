#include <math.h>
#include "Line.h"
#include <iostream>
#include <iomanip>

Line::Line() { k = 1, b = 0; }

Line::Line(double initK, double initB) { k = initK, b = initB; }

double Line::getK() const { return k; }

double Line::getB() const { return b; }

void Line::print()
{
    double printk = (floor((k * 100) + .5)) / 100;
    double printb = (floor((b * 10) + .5)) / 10;

    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::right << "The line is y = " << std::setw(6) << printk
              << " * x + " << std::setw(5) << printb << std::endl;
}

bool Line::operator==(const Line &l2) const { return ((k == l2.getK()) && (b == l2.getB())); }

void Line::operator*(double multiplier) { k *= multiplier; }

void Line::operator+(double addend) { b += addend; }
