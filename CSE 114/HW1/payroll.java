/*
Daniel Langer
114662901
payroll program, takes inputs and calculates gross and net pay
*/

import java.util.Scanner;

public class payroll {
    public static void main(String[] args) {
        // Scanner to get all information
        Scanner input = new Scanner(System.in);
        System.out.println("What is the employee's name?");
        String lname = input.next();

        System.out.println("How many hours worked in a week?");
        int hours = input.nextInt();

        System.out.println("What is the hourly pay rate?");
        float hourlyPay = input.nextFloat();

        System.out.println("What is the federal withholding rate?");
        float fedRate = input.nextFloat() / 100;

        System.out.println("What is the state withholding rate?");
        float stateRate = input.nextFloat() / 100;

        input.close();

        // Calculate gross pay and how much state and federal withhold
        float grossWages = hours * hourlyPay;
        float fedWithheld = grossWages * fedRate;
        float stateWithheld = grossWages * stateRate;

        System.out.printf("%s worked %d hours at %.2f per hour\nGross = %.2f and net = %.2f", lname, hours,
                hourlyPay, grossWages, grossWages - (fedWithheld + stateWithheld));
    }
}
