#include "Line.cpp"
#include "Rectangle.cpp"

using namespace std;

double resolveEquation(double x, double y, Line l)
{
    double slope = l.getK();
    double intercept = l.getB();

    // If 0, that means the line passes through the point
    // If positive, that means the line is above that point
    // If negative, that means the line is below that point
    // If all 4 corners are either above or below that means they dont intersect

    return ((slope * x) + intercept - y);
}

bool isIntersect(Rectangle r, Line l)
{
    // Get all four corners of the rectangle
    double rectCorners[4][2] = {
        {r.getX() - abs(r.getWidth() / 2), r.getY() - abs(r.getHeight() / 2)},
        {r.getX() - abs(r.getWidth() / 2), r.getY() + abs(r.getHeight() / 2)},
        {r.getX() + abs(r.getWidth() / 2), r.getY() - abs(r.getHeight() / 2)},
        {r.getX() + abs(r.getWidth() / 2), r.getY() + abs(r.getHeight() / 2)}};

    int pos = 0, neg = 0;
    for (int i = 0; i < 4; i++)
    {
        double sendX = rectCorners[i][0];
        double sendY = rectCorners[i][1];

        double resolveResult = resolveEquation(sendX, sendY, l);

        if (resolveResult == 0)
            return true;
        else if (resolveResult > 0)
            pos++;
        else if (resolveResult < 0)
            neg++;
    }

    if (pos == 4 || neg == 4)
        return false;
    else
        return true;
}

int main()
{
    double x, y, w, h, k, b;
    bool intersect;
    cout << "Enter rectangle parameters (x, y, w, h): ";
    cin >> x >> y >> w >> h;
    Rectangle rect(x, y, w, h);
    cout << "Enter line parameters (k, b): ";
    cin >> k >> b;
    Line line(k, b);
    intersect = isIntersect(rect, line);
    cout << "Is the rectangle and line intersect? " << intersect << endl;
    return 0;
}
