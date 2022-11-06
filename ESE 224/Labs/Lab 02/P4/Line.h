#pragma once

class Line
{
private:
    double k, b;

public:
    Line();
    Line(double initK, double initB);
    double getK() const;
    double getB() const;
    void print();
    bool operator==(const Line &l2) const;
    void operator*(double multiplier);
    void operator+(double addend);
};
