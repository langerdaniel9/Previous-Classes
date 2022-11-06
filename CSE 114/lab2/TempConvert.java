/*
Daniel Langer
114662901
Converts an input in degrees Celcius to degrees Farenheight 
*/

import java.util.Scanner;

public class TempConvert {
    public static void main(String[] args) {
        double degreesC, degreesF;
        System.out.println("What is the temperature in C?");
        Scanner input = new Scanner(System.in);
        degreesC = input.nextDouble();
        input.close();
        degreesF = (degreesC * (9.0 / 5.0)) + 32;
        System.out.println(String.format("%.2f degrees in C is %.2f in F.", degreesC, degreesF));
    }
}
