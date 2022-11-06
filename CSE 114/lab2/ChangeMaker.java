
/**
* Input a change amount and display required number of quarters, nickels,
* dimes and pennies to make any amount from 1 to 99 cents.
* 
* Include your name and ID number here 
* Daniel Langer
* 114662901
*/
import java.util.Scanner;

public class ChangeMaker {
    public static void main(String[] args) {
        int amount, originalAmount, quarters, dimes, nickels, pennies;

        System.out.print("Input change amount (1-99): ");
        Scanner input = new Scanner(System.in);
        amount = input.nextInt();
        input.close();
        originalAmount = amount;
        quarters = amount / 25;
        amount = amount % 25;
        dimes = amount / 10; // Make mistake here / to %
        amount = amount % 10;
        nickels = amount / 5;
        amount = amount % 5; // Make mistake here % to /
        pennies = amount;

        System.out.println(originalAmount + " cents in coins can be given as:");
        System.out.println(quarters + " quarters");
        System.out.println(dimes + " dimes");
        System.out.println(nickels + " nickels and");
        System.out.println(pennies + " pennies");
    }
}