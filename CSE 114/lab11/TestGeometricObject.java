/*
 * Daniel Langer
 * 114662901
 */

abstract class GeometricObject {
    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;

    protected GeometricObject() {
        dateCreated = new java.util.Date();
    }

    protected GeometricObject(String color, boolean filled) {
        this();
        this.color = color;
        this.filled = filled;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public java.util.Date getDateCreated() {
        return dateCreated;
    }

    public String toString() {
        return "color: " + color + ", filled: " + filled
                + ", created on " + dateCreated;
    }

    /** Abstract method getArea */
    public abstract double getArea();

    /** Abstract method getPerimeter */
    public abstract double getPerimeter();
}

class Triangle extends GeometricObject {
    private double side1, side2, side3 = 1.0;

    public Triangle() {
    }

    public Triangle(double initSide1, double initSide2, double initSide3) {
        this();
        side1 = initSide1;
        side2 = initSide2;
        side3 = initSide3;
    }

    public double getSide1() {
        return side1;
    }

    public double getSide2() {
        return side2;
    }

    public double getSide3() {
        return side3;
    }

    public double getArea() {
        double s = (side1 + side2 + side3) / 2;
        return (Math.sqrt((s) * (s - side1) * (s - side2) * (s - side3)));
    }

    public double getPerimeter() {
        return side1 + side2 + side3;
    }

    public String toString() {
        return "This triange has sides of length " + side1 + ", " + side2 + ", and " + side3 + ", with an area of "
                + this.getArea() + " and a perimeter of " + this.getPerimeter() + " " + super.toString();
    }
}

public class TestGeometricObject {
    public static void main(String[] args) {
        Triangle test = new Triangle(1, 1.5, 1);
        GeometricObject test2 = test;
        System.out.println(test2.toString());
    }
}