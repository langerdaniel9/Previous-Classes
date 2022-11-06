#pragma once

class Point
{
private:
    double xCoord, yCoord;

public:
    Point();
    Point(double initX, double initY);
    double getX();
    double getY();
    void setX(double setX);
    void setY(double setY);
    double toOrigin();
    double Distance(const Point &p2) const;
    double operator-(const Point &p2);
    bool Equal(const Point &p2) const;
    bool operator==(const Point &p2) const;
    void Print();
};
