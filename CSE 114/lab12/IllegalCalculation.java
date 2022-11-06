/* 
 * Daniel Langer
 * 114662901
 */

import java.util.Scanner;

class IllegalOperatorException extends Exception {
    public IllegalOperatorException() {
        super("Illegal operator");
    }
}

class DivideByZeroException extends Exception {
    public DivideByZeroException() {
        super("Divide by zero");
    }
}

public class IllegalCalculation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a simple mathematical operation:");
        String num1 = input.next(), operator = input.next(), num2 = input.next();
        input.close();

        boolean error = false;
        double result = 0, first = 0, second = 0;

        try {
            first = Double.parseDouble(num1);
            second = Double.parseDouble(num2);
        } catch (NumberFormatException e) {
            error = true;
            System.out.println(e);
        }

        try {
            switch (operator) {
                case "+": {
                    result = first + second;
                    break;
                }
                case "-": {
                    result = first - second;
                    break;
                }
                case "*": {
                    result = first * second;
                    break;
                }
                case "/": {
                    if (second == 0) {
                        error = true;
                        throw new DivideByZeroException();
                    }
                    break;
                }

                default:
                    error = true;
                    throw new IllegalOperatorException();
            }
        } catch (IllegalOperatorException e) {
            System.out.println(e);
        } catch (DivideByZeroException e) {
            System.out.println(e);
        }
        if (!error) {
            System.out.println("The answer is " + result);
        }
    }
}
