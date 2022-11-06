/*
Daniel Langer
114662901
Prints a table with a conversion between miles and kilometers
*/

public class part1 {
    public static void main(String[] args) {
        System.out.println("Miles\tKilometers");
        for (int miles = 1; miles <= 10; miles++) {
            Double kilometers = miles * 1.609;
            System.out.printf("%d\t%.3f\n", miles, kilometers);
        }
    }
}
