#include "Rectangle.cpp"
#include <iostream>
using namespace std;

double compute_IOU(Rectangle r1, Rectangle r2)
{
    // Intersecting rectangle
    double r1LL[2], r1UR[2], r2LL[2], r2UR[2]; // LL is lower left, UR is upper right

    // Get coordinates of lower left and upper right points

    r1LL[0] = r1.getX() - abs(r1.getWidth() / 2), r1LL[1] = r1.getY() - abs(r1.getHeight() / 2);
    r1UR[0] = r1.getX() + abs(r1.getWidth() / 2), r1UR[1] = r1.getY() + abs(r1.getHeight() / 2);

    r2LL[0] = r2.getX() - abs(r2.getWidth() / 2), r2LL[1] = r2.getY() - abs(r2.getHeight() / 2);
    r2UR[0] = r2.getX() + abs(r2.getWidth() / 2), r2UR[1] = r2.getY() + abs(r2.getHeight() / 2);

    // Find length and width of intersecting rectangle
    double overlapXLength = min(r1UR[0], r2UR[0]) - max(r1LL[0], r2LL[0]);
    double overlapYLength = min(r1UR[1], r2UR[1]) - max(r1LL[1], r2LL[1]);

    // if either of the lengths are negative then the rectangles do not intersect
    if (overlapXLength < 0 || overlapYLength < 0)
    {
        return 0;
    }

    double aOverlap = overlapXLength * overlapYLength;
    double aUnion = r1.getArea() + r2.getArea() - aOverlap;

    return aOverlap / aUnion;
}

int main()
{
    double x, y, w, h, iou;
    cout << "Enter rectangle 1 (x, y, w, h): ";
    cin >> x >> y >> w >> h;
    Rectangle r1(x, y, w, h);

    cout << "Enter rectangle 2 (x, y, w, h): ";
    cin >> x >> y >> w >> h;
    Rectangle r2(x, y, w, h);

    iou = compute_IOU(r1, r2);
    cout << "The IOU of r1 and r2 is: " << iou << endl;

    return 0;
}
