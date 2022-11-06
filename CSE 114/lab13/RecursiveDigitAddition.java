/*
 * Daniel Langer
 * 11462901
 */

import java.util.Scanner;

public class RecursiveDigitAddition {
    public static int sumDigits(long n) {
        String toAdd = Long.toString(n);
        if (toAdd.length() == 1) {
            return (int) n;
        }
        String subString = toAdd.substring(1);
        return (int) Long.parseLong((toAdd.substring(0, 1))) + sumDigits(Long.parseLong(subString));
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a number:");
        long entered = input.nextLong();
        input.close();
        System.out.println("The result is: " + sumDigits(entered));
    }
}
