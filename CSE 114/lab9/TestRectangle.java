/*
 * Daniel Langer
 * 114662901
 * Classes with rectangles
 */

class Rectangle {
    /** The default height/width/color of this rectangle */
    private double height = 1.0;
    private double width = 1.0;
    private String color = "white";

    /** Construct a rectangle object */
    public Rectangle() {
    }

    /** Construct a rectangle object */
    public Rectangle(double initHeight, double initWidth) {
        height = initHeight;
        width = initWidth;
    }

    /** Set width of a rectangle object */
    public void setWidth(double newWidth) {
        width = newWidth;
    }

    /** Set height of a rectangle object */
    public void setHeight(double newHeight) {
        height = newHeight;
    }

    /** Set color of a rectangle object */
    public void setColor(String newColor) {
        color = newColor;
    }

    /** Return width of a rectangle object */
    public double getWidth() {
        return width;
    }

    /** Return height of a rectangle object */
    public double getHeight() {
        return height;
    }

    /** Return color of a rectangle object */
    public String getColor() {
        return color;
    }

    /** Return the area of this rectangle */
    public double getArea() {
        return height * width;
    }

    /** Return the perimeter of this rectangle */
    public double getPerimeter() {
        return (2 * height) + (2 * width);
    }
}

public class TestRectangle {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(40, 4);
        Rectangle r2 = new Rectangle(35.9, 3.5);
        r1.setColor("red");
        r2.setColor("red");

        System.out.printf(
                "Rectangle 1 has a height of %f, width of %f, and is %s. Its area is %f and its perimeter is %f\n",
                r1.getHeight(), r1.getWidth(), r1.getColor(), r1.getArea(), r1.getPerimeter());

        System.out.printf(
                "Rectangle 2 has a height of %f, width of %f, and is %s. Its area is %f and its perimeter is %f\n",
                r2.getHeight(), r2.getWidth(), r2.getColor(), r2.getArea(), r2.getPerimeter());
    }
}
