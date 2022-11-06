/*
Daniel Langer
114662901
Counts positive and negative numbers and computes the average
*/

import java.util.Scanner;

public class part3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int total = 0;
        int countOdd = 0;
        int countEven = 0;

        System.out.println("Input numbers ended by 0:\n");

        int number = input.nextInt();
        while (number != 0) {
            total += number;
            if (number % 2 == 0) {
                countEven++;
            } else {
                countOdd++;
            }
            number = input.nextInt();
        }

        input.close();
        double average = (total * 1.0) / (countEven + countOdd);
        System.out.printf("Odd numbers: %d\nEven numbers: %d\nTotal: %d\nAverage: %.2f", countOdd, countEven, total,
                average);
    }
}
