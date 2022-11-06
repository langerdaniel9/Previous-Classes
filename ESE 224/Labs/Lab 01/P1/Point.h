#pragma

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
};
