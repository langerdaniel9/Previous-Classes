/*
 * Daniel Langer
 * 114662901
 * This is both part 3 and part 4
 */

abstract class GeometricObject implements Cloneable, Comparable<GeometricObject> {
    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;

    protected GeometricObject() {
        dateCreated = new java.util.Date();
    }

    protected GeometricObject(String color, boolean filled) {
        dateCreated = new java.util.Date();
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
        return "created on " + dateCreated + " color: " + color +
                " and filled: " + filled;
    }

    public int compareTo(GeometricObject compare) {
        double area1 = this.getArea();
        double area2 = compare.getArea();

        if (area1 > area2) {
            return 1;
        } else if (area1 < area2) {
            return -1;
        } else {
            return 0;
        }
    }

    public static GeometricObject max(GeometricObject object1, GeometricObject object2) {
        double area1 = object1.getArea();
        double area2 = object2.getArea();

        if (area1 > area2) {
            return object1;
        } else {
            return object2;
        }
    }

    public abstract double getArea();

    public abstract double getPerimeter();

    public abstract GeometricObject clone();
}

class Rectangle extends GeometricObject {
    private double length = 3;
    private double width = 5;

    public Rectangle() {
    }

    public Rectangle(double initLength, double initWidth) {
        length = initLength;
        width = initWidth;
    }

    public Rectangle(String color, boolean filled) {
        super(color, filled);
    }

    public Rectangle(String color, boolean filled, double initLength, double initWidth) {
        super(color, filled);
        length = initLength;
        width = initWidth;
    }

    public double getLength() {
        return length;
    }

    public double getWidth() {
        return width;
    }

    public double getArea() {
        return length * width;
    }

    public double getPerimeter() {
        return (2 * length) + (2 * width);
    }

    public boolean equals(Rectangle rect2) {
        double length1 = this.getLength();
        double width1 = this.getLength();
        String color1 = this.getColor();
        boolean filled1 = this.isFilled();
        double length2 = rect2.getLength();
        double width2 = rect2.getLength();
        String color2 = rect2.getColor();
        boolean filled2 = rect2.isFilled();

        if (length1 == length2 && width1 == width2 && color1 == color2 && filled1 == filled2) {
            return true;
        } else {
            return false;
        }
    }

    public Rectangle clone() {
        double cloneLength = this.getLength();
        double cloneWidth = this.getWidth();
        boolean cloneFilled = this.isFilled();
        String cloneColor = this.getColor();
        Rectangle toReturn = new Rectangle(cloneColor, cloneFilled, cloneLength, cloneWidth);
        return toReturn;
    }

    public String toString() {
        return "Rectangle with width: " + width + ", length: " + length + " " + super.toString();
    }
}

class Circle extends GeometricObject {
    private double radius = 1;

    public Circle() {
    }

    public Circle(double initRadius) {
        radius = initRadius;
    }

    public Circle(String color, boolean filled) {
        super(color, filled);
    }

    public Circle(String color, boolean filled, double initRadius) {
        super(color, filled);
        radius = initRadius;
    }

    public double getRadius() {
        return radius;
    }

    public double getArea() {
        return 3.141592 * radius * radius;
    }

    public double getPerimeter() {
        return 2 * 3.141592 * radius;
    }

    public Circle clone() {
        double cloneRadius = this.getRadius();
        boolean cloneFilled = this.isFilled();
        String cloneColor = this.getColor();
        Circle toReturn = new Circle(cloneColor, cloneFilled, cloneRadius);
        return toReturn;
    }

    public boolean equals(Circle circ2) {
        double radius1 = this.getRadius();
        String color1 = this.getColor();
        boolean filled1 = this.isFilled();
        double radius2 = circ2.getRadius();
        String color2 = circ2.getColor();
        boolean filled2 = circ2.isFilled();

        if (radius1 == radius2 && color1 == color2 && filled1 == filled2) {
            return true;
        } else {
            return false;
        }
    }

    public String toString() {
        return "Circle of radius " + radius + " " + super.toString();
    }
}

public class TestGeometricObject {
    public static void main(String[] args) {
        // Part 3 - use max to find the larger of 2 circles and larger of 2 rectangles
        GeometricObject rect1 = new Rectangle(2, 3);
        GeometricObject rect2 = new Rectangle(4, 5);
        GeometricObject circ1 = new Circle("White", true, 2);
        GeometricObject circ2 = new Circle("Orange", true, 6);
        System.out.println(GeometricObject.max(rect1, rect2));
        System.out.println(GeometricObject.max(circ1, circ2));

        System.out.println();

        // Part 4 - clone a rectangle
        Rectangle obj1 = new Rectangle("Green", true);
        Rectangle obj2 = obj1.clone();
        System.out.println("obj1: " + obj1.toString());
        System.out.println("obj2: " + obj2.toString());
        System.out.println("obj1 == obj2 is " + (obj1 == obj2));
        System.out.println("obj1.equals(obj2) is " + (obj1.equals(obj2)));

    }
}
