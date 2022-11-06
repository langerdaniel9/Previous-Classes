class Circle
{
private:
    double centerX;
    double centerY;
    double radius;

public:
    Circle(double initCenterX, double initCenterY, double initRadius);
    double getCenterX() const;
    double getCenterY() const;
    double getRadius() const;
    void print();
    void operator*(double multiplier);
    bool operator==(const Circle &C2) const;
};
