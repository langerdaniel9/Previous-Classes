/*
Daniel Langer
114662901
Creates triangle showing powers of 2
*/

import java.util.Scanner;

public class pyramid {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("How many lines?");
        int lines = input.nextInt();
        input.close();

        for (int i = 0; i <= lines; i++) {
            // Prints the spaces to make it look like a triangle, purely aesthetic, doesnt
            // work too well past 2/3 digit numbers
            for (int k = 0; k < (lines - i); k++) {
                System.out.print("  ");
            }
            // Goes up until the largest number which will be in the middle
            int j = 0;
            while (j < i) {
                System.out.printf("%d ", (int) Math.pow(2, j));
                j++;
            }
            // Picks up from the largest number and starts incrementing down
            j -= 2;
            while (j >= 0) {
                System.out.printf("%d ", (int) Math.pow(2, j));
                j--;
            }
            System.out.println();
        }
    }
}
