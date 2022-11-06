/*
Daniel Langer
114662901
isbn checksum calculator
*/

import java.util.Scanner;

public class isbn {
    public static void main(String[] args) {
        System.out.print("What are the first 9 digits of the ISBN?\n");
        Scanner input = new Scanner(System.in);
        int entered = input.nextInt();
        input.close();

        String firstNine = String.format("%09d", entered); // If it is shorter than 9 digits, add zeros
        if (firstNine.length() > 9) { // If its too long, exit
            System.out.println("More than 9 digits, try again");
            return;
        }

        int checkSum = 0;
        for (int i = 1; i < 10; i++) {
            checkSum += Character.getNumericValue(firstNine.charAt(i - 1)) * i;
        }

        checkSum %= 11;

        String isbn;

        if (checkSum == 10) {
            isbn = firstNine.concat("X");
        } else {
            isbn = firstNine.concat(Integer.toString(checkSum));
        }

        System.out.println(isbn);
    }
}
