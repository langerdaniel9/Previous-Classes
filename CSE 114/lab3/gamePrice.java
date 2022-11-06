/*
Daniel Langer
114662901
Calculates discount based on normal price and games bought
*/

import java.util.Scanner;

public class gamePrice {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter regular price:");
        double standardPrice = input.nextDouble();

        System.out.println("Enter quantity:");
        int quantity = input.nextInt();

        input.close();

        // Calculate discount
        double discount = 0.0;
        if (quantity >= 100) {
            discount = 0.50;
        } else if (quantity >= 50) {
            discount = 0.40;
        } else if (quantity >= 20) {
            discount = 0.30;
        } else if (quantity >= 10) {
            discount = 0.20;
        }

        double ppg = standardPrice * (1 - discount); // ppg = price per game

        System.out.printf(
                "\nDiscount: %.0f%%\nDiscounted price: $%.2f\nDiscounted amount per item %.2f\n\nTotal price: $%.2f * %d = $%.2f",
                discount * 100, ppg, standardPrice - ppg, ppg, quantity, ppg * quantity);

    }
}
