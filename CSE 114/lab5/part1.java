/*
Daniel Langer
114662901
Converts decimal to binary
*/

import java.util.Scanner;

public class part1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Input a number: ");
        int decimal = input.nextInt();
        input.close();

        String binary = "";
        int i = 0;

        // Finds the number of digits in the binary value
        while (Math.pow(2, i) <= decimal) {
            i++;
        }

        // Finds the binary value by subtracting the largest possible digit
        for (int j = i - 1; j >= 0; j--) {
            if (decimal - Math.pow(2, j) >= 0) {
                decimal -= Math.pow(2, j);
                binary += "1";
            } else {
                binary += "0";
            }
        }

        // Prints the binary value starting at the LSB
        for (int k = i - 1; k >= 0; k--) {
            System.out.println(binary.charAt(k));
        }

    }
}
