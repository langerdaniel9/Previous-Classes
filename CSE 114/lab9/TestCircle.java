/*
 * Daniel Langer
 * 114662901
 * 
 */

class Circle {
    /** The default radius of this circle */
    private double radius = 1.0;

    /** Construct a circle object */
    public Circle() {
    }

    /** Construct a circle object */
    public Circle(double initRadius) {
        radius = initRadius;
    }

    /** set radius of a circle object */
    public void setRadius(double newRadius) {
        radius = newRadius;
    }

    /** return radius of a circle object */
    public double getRadius() {
        return radius;
    }

    /** Return the area of this circle */
    public double getArea() {
        return radius * radius * 3.14159;
    }
}

public class TestCircle {
    public static void main(String[] args) {
        Circle c1 = new Circle(); // default radius is 1.0
        Circle c2 = new Circle(5.0);

        System.out.println(c1.getArea());
        System.out.println(c2.getArea());

        c1.setRadius(10);
        System.out.println("Area of a circle with radius " + c1.getRadius() +
                " is " + c1.getArea());
    }
}