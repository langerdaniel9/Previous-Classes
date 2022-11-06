/*
Daniel Langer
114662901
Calculates amount of fuel used based on speed, time, and efficiency
*/

import java.util.Scanner;

public class fuelEfficiency {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("How many minutes has the car been driving?");
        double mins = input.nextDouble();

        System.out.println("Whats the speed of the car in mph?");
        double mph = input.nextDouble();

        System.out.println("Whats the fuel efficiency of the car in mpg?");
        double mpg = input.nextDouble();

        double gasConsumed = ((mins / 60.0) * mph) / mpg;

        System.out.println("The amount of gas consumed is " + gasConsumed);

        input.close();
    }
}
