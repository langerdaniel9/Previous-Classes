/*
 * Daniel Langer
 * 114662901
 */

interface Colorable {
    public abstract void howToColor();
}

class GeometricObject {
    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;

    public GeometricObject() {
        dateCreated = new java.util.Date();
    }

    public GeometricObject(String color, boolean filled) {
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
}

class Square extends GeometricObject implements Colorable {
    private double sideLength;

    public Square() {
        super();
        sideLength = 5;
    }

    public Square(double initSideLength) {
        super();
        sideLength = initSideLength;
    }

    public Square(String color, boolean filled, double initSideLength) {
        super(color, filled);
        sideLength = initSideLength;
    }

    public void howToColor() {
        System.out.println("Square: Use a marker");
    }

    public double getSideLength() {
        return sideLength;
    }

    public double getArea() {
        return sideLength * sideLength;
    }

    public double getPerimeter() {
        return (4 * sideLength);
    }

    public String toString() {
        return "Square with side length " + sideLength + ", color " + super.getColor() + ", filled = "
                + super.isFilled() + ", created on " + super.getDateCreated();
    }
}

public class TestColorable {
    public static void main(String[] args) {
        GeometricObject[] array = new GeometricObject[5];

        array[0] = new GeometricObject("Blue", true);
        array[1] = new Square("Orange", true, 3);
        array[2] = new GeometricObject("Red", false);
        array[3] = new Square("Green", false, 8);
        array[4] = new GeometricObject();

        for (GeometricObject object : array) {
            System.out.println(object.toString());
            if (object instanceof Colorable && object instanceof Square) {
                ((Square) object).howToColor();
            }
        }
    }
}
