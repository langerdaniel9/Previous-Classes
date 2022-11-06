/*
Daniel Langer
114662901
Checks if triangle is valid based on side lengths
*/

import java.util.Scanner;

public class validTriangle {
    public static void main(String[] args) {
        System.out.println("Enter the three side lengths of a triangle:");
        Scanner input = new Scanner(System.in);
        int side1 = input.nextInt();
        int side2 = input.nextInt();
        int side3 = input.nextInt();
        input.close();

        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            System.out.println("That triangle is invalid");
        } else {
            System.out.println("That triangle is valid");
        }
    }
}
