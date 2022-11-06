/*
Daniel Langer
114662901
Prints two tables side by side with conversions with miles and kilometers
*/

public class part2 {
    public static void main(String[] args) {
        System.out.println("Kilogram Pound     Pound2     Kilogram2");
        for (int kilogram = 1; kilogram <= 199; kilogram += 2) {
            Double pound = kilogram * 2.2;
            int pound2 = 20 + (5 * (kilogram / 2));
            Double kilogram2 = pound2 / 2.2;
            System.out.printf("%-8d %-9.1f %-10d %-9.2f \n", kilogram, pound, pound2, kilogram2);
        }
    }
}
