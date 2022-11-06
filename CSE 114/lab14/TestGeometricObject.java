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
        return "created on " + dateCreated + "\ncolor: " + color +
                " and filled: " + filled;
    }
}

class CloneableGeometricObject extends GeometricObject implements Cloneable, Comparable {

    public CloneableGeometricObject(String initColor, boolean initFilled) {
        super(initColor, initFilled);
    }

    public CloneableGeometricObject clone() {
        CloneableGeometricObject toReturn = new CloneableGeometricObject(this.getColor(), this.isFilled());
        return toReturn;
    }

    public int compareTo(Object toCompare) {
        if (super.getDateCreated().getTime() > ((CloneableGeometricObject) toCompare).getDateCreated().getTime()) {
            return -1;
        } else if (super.getDateCreated().getTime() < ((CloneableGeometricObject) toCompare).getDateCreated()
                .getTime()) {
            return 1;
        } else {
            return 0;
        }
    }
}

public class TestGeometricObject {
    public static void main(String[] args) {
        CloneableGeometricObject obj1 = new CloneableGeometricObject("Green", true);
        CloneableGeometricObject obj2 = obj1.clone();
        System.out.println(obj1.toString());
        System.out.println(obj2.toString());

        CloneableGeometricObject obj3 = new CloneableGeometricObject("White", false);
        System.out.println(obj1.getDateCreated().getTime());
        System.out.println(obj3.getDateCreated().getTime());
        System.out.println(obj3.compareTo(obj1));
        System.out.println(obj1.compareTo(obj3));
        System.out.println(obj1.compareTo(obj1));
    }
}
