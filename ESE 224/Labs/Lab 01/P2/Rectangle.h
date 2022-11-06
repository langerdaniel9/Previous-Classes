#pragma

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
    double getArea();
    void makeMirrorX();
    void makeMirrorY();
    void makeMirrorOrigin();
    std::string toString();
};
