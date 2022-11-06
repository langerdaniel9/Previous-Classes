/*
 * Daniel Langer
 * 114662901
 * Class to represent a fan
 */

class Fan {
    final int SLOW = 1;
    final int MEDIUM = 2;
    final int FAST = 3;

    int speed;
    boolean on;
    double radius;
    String color;

    // ** Cosntruct a fan object*/
    public Fan() {
        speed = SLOW;
        on = false;
        radius = 5;
        color = "blue";
    }

    // ** Return speed of fan object*/
    public int speed() {
        return speed;
    }

    // ** Set speed of fan object*/
    public void setSpeed(int initSpeed) {
        speed = initSpeed;
    }

    // ** Return on status of fan object*/
    public boolean on() {
        return on;
    }

    // ** Set on status of fan object */
    public void setOn(boolean initOn) {
        on = initOn;
    }

    // ** Return radius of fan object*/
    public double radius() {
        return radius;
    }

    // ** Set radius of fan object*/
    public void setRadius(double initRadius) {
        radius = initRadius;
    }

    // ** return color of fan object*/
    public String color() {
        return color;
    }

    // ** Set color of fan object */
    public void setColor(String initColor) {
        color = initColor;
    }

    // ** Return all values of fan object as a single string*/
    public String toString() {
        if (on) {
            return String.format("The fan is running at speed %s, its color is %s, and the radius is " + radius, speed,
                    color);
        } else {
            return String.format("The fan is off, is %s in color, and has the radius " + radius, color);
        }
    }
}

public class TestFan {
    public static void main(String[] args) {
        Fan fan1 = new Fan();
        Fan fan2 = new Fan();

        fan1.setSpeed(3);
        fan1.setRadius(10);
        fan1.setColor("yellow");
        fan1.setOn(true);
        System.out.println("Fan 1: " + fan1.toString());

        fan2.setSpeed(2);
        fan2.setRadius(5);
        fan2.setColor("blue");
        fan2.setOn(false);

        System.out.println("Fan 2: " + fan2.toString());
    }
}
