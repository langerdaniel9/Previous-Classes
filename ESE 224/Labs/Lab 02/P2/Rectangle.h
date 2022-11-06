#pragma once

class Rectangle
{
private:
    double xCoord, yCoord, width, height;

public:
    Rectangle();
    Rectangle(double initX, double initY, double initW, double initH);
    double getX();
    double getY();
    double getWidth();
    double getHeight();
    double getArea() const;
    void makeMirrorX();
    void makeMirrorY();
    void makeMirrorOrigin();
    bool operator>(const Rectangle &r2) const;
    double operator-(const Rectangle &r2) const;
    void print();
};
