/*
 * Daniel Langer
 * 114662901
 */

class Circle {
    double x, y, radius;

    public Circle() {
        x = 0;
        y = 0;
        radius = 1;
    }

    public Circle(double xCenter, double yCenter, double rad) {
        x = xCenter;
        y = yCenter;
        radius = rad;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getRadius() {
        return radius;
    }

    public double getArea() {
        return (3.1415 * radius * radius);
    }

    public double getCircumference() {
        return (2 * 3.1415 * radius);
    }

    public boolean contains(double xCoord, double yCoord) {
        double distance = Math.sqrt((xCoord - x) * (xCoord - x) + (yCoord - y) * (yCoord - y));
        if (distance <= radius) {
            return true;
        } else {
            return false;
        }
    }

    public boolean contains(Circle circle2) {
        double distance = Math
                .sqrt(((circle2.getX() - x) * (circle2.getX() - x)) + ((circle2.getY() - y) * (circle2.getY() - y)));
        if (distance + circle2.getRadius() < radius) {
            return true;
        } else {
            return false;
        }
    }

    public boolean overlaps(Circle circle2) {
        double distance = Math
                .sqrt(((circle2.getX() - x) * (circle2.getX() - x)) + ((circle2.getY() - y) * (circle2.getY() - y)));
        if (distance < radius + circle2.getRadius()) {
            return true;
        } else {
            return false;
        }
    }

}

public class Circle2D {
    public static void main(String[] args) {
        Circle circle1 = new Circle(1, 1, 2);
        Circle circle2 = new Circle(2, 2, 2);

        System.out.printf(
                "Circle 1 has coordinates of (%f, %f) with a radius of %f, an area of %f, and a circumfrence of %f\n",
                circle1.getX(), circle1.getY(), circle1.getRadius(), circle1.getArea(), circle1.getCircumference());
        System.out.printf(
                "Circle 2 has coordinates of (%f, %f) with a radius of %f, an area of %f, and a circumfrence of %f\n",
                circle2.getX(), circle2.getY(), circle2.getRadius(), circle2.getArea(), circle2.getCircumference());

        if (circle2.contains(circle1)) {
            System.out.println("Circle 2 contains circle 1");
        }

        if (circle1.contains(2, 3)) {
            System.out.println("Circle 1 contains the point (2, 3)");
        } else {
            System.out.println("Circle 1 doesnt contain the point (2, 3)");
        }

        if (circle2.contains(2, 3)) {
            System.out.println("Circle 2 contains the point (2, 3)");
        } else {
            System.out.println("Circle 2 doesnt contain the point (2, 3)");
        }

        if (circle2.overlaps(circle1)) {
            System.out.println("Circle 1 overlaps with circle 2");
        }
    }
}
