/*
 * Daniel Langer
 * 114662901
 */

class IllegalTriangleException extends Exception {
    public IllegalTriangleException() {
        super("Invalid side lengths");
    }
}

class Triangle {
    private double side1, side2, side3 = 1.0;

    public Triangle() {
    }

    /** Construct a triangle with the specified sides */
    public Triangle(double initSide1, double initSide2, double initSide3) throws IllegalTriangleException {
        this();
        if (initSide1 + initSide2 < initSide3 || initSide2 + initSide3 < initSide3
                || initSide1 + initSide3 < initSide2) {
            throw new IllegalTriangleException();
        } else {
            side1 = initSide1;
            side2 = initSide2;
            side3 = initSide3;
        }

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

public class IllegalTrianglesException {
    public static void main(String[] args) {
        Triangle normalTriangle = new Triangle();
        Triangle testException = new Triangle();
        try {
            normalTriangle = new Triangle(3, 4, 5);
            testException = new Triangle(1, 2, 8);
        } catch (IllegalTriangleException exception) {
            System.out.println(exception);
        } finally {
            System.out.println(normalTriangle.getArea());
            System.out.println(testException.getArea());
        }
    }
}
