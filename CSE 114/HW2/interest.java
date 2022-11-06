/*
Daniel Langer
114662901
Takes in a loan amount and loan period and gives possible rates and payments
*/

import java.util.Scanner;

public class interest {
    public static void main(String[] args) {
        // Get all of the input values with the scanner
        Scanner input = new Scanner(System.in);
        System.out.println("What is the loan amount?");
        double loanAmount = input.nextDouble();
        System.out.println("What is the loan period");
        int loanPeriod = input.nextInt();
        input.close();

        // Calculates and prints the values
        System.out.println("Interest Rate\tMontly Payment\tTotal Payment");
        for (double interestRate = 5; interestRate <= 8; interestRate += .125) {
            Double monthlyInterestRate = interestRate / 1200;
            Double montlyPayment = loanAmount * monthlyInterestRate
                    / (1 - (Math.pow(1 / (1 + monthlyInterestRate), loanPeriod * 12)));
            Double totalPayment = montlyPayment * 12 * loanPeriod;
            System.out.printf("%.3f%%\t\t%.2f\t\t%.2f\n", interestRate, montlyPayment, totalPayment);
        }
    }
}
