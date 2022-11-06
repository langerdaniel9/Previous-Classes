/*
Daniel Langer
114662901
User selected conversion tool
*/

import java.util.Scanner;

public class part3 {
    public static double lbToKg(double pounds) {
        return (pounds / 2.205);
    }

    public static double kgTolb(double kilogram) {
        return (kilogram * 2.205);
    }

    public static double kmToMi(double kilometers) {
        return (kilometers / 1.609);
    }

    public static double miToKm(double miles) {
        return (miles * 1.609);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println(
                "A - convert pounds to kilos\nB - convert kilos to pounds\nC - convert kilometers to miles\nD - convert miles to kilometers\nE - Exit");

        while (true) {
            System.out.println("Enter the option you want:");
            char selection = input.next().charAt(0);

            switch (selection) {
                case 'A': {
                    System.out.println("How many pounds?");
                    double pounds = input.nextDouble();
                    System.out.println(pounds + " pounds is " + lbToKg(pounds) + " kilograms");
                    break;
                }

                case 'B': {
                    System.out.println("How many kilograms?");
                    double kilograms = input.nextDouble();
                    System.out.println(kilograms + " kilograms is " + kgTolb(kilograms) + " pounds");
                    break;
                }

                case 'C': {
                    System.out.println("How many kilometers?");
                    double kilometers = input.nextDouble();
                    System.out.println(kilometers + " kilometers is " + kmToMi(kilometers) + " miles");
                    break;
                }

                case 'D': {
                    System.out.println("How many miles?");
                    double miles = input.nextDouble();
                    System.out.println(miles + " miles is " + miToKm(miles) + " kilometers");
                    break;
                }

                case 'E': {
                    input.close();
                    return;
                }

                default: {
                    System.out.println("Thats not a valid option, try again");
                    break;
                }
            }
        }
    }
}
