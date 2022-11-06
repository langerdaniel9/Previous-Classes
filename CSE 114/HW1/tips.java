/*
Daniel Langer
114662901
tip calculator, takes a subtotal and gratuity rate as input and calculates the gratuity amount and the total
*/

import java.util.Scanner;

public class tips {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("What is the subtotal?");
        int subtotal = input.nextInt();

        System.out.println("What is the gratuity rate?");
        float gratuityPercent = input.nextFloat() / 100;

        input.close();

        float gratuity = subtotal * gratuityPercent;
        float total = (subtotal + gratuity);
        System.out.printf("The gratuity is %.2f and the total is %.2f", gratuity, total);
    }
}