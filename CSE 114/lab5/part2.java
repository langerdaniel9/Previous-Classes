/*
Daniel Langer
114662901
Converts decimal to hex
*/

import java.util.Scanner;

public class part2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Input a number: ");
        int decimal = input.nextInt();
        input.close();

        String hex = "";
        int i = 0;

        // Finds the number of digits in the hex value
        while (Math.pow(16, i) <= decimal) {
            i++;
        }

        // Finds the hex value starting at the largest possible digit
        for (int j = i - 1; j >= 0; j--) {
            for (int l = 15; l >= 0; l--) {
                if (decimal - (Math.pow(16, j) * l) >= 0) {
                    switch (l) {
                        case 10: {
                            hex += "A";
                            break;
                        }
                        case 11: {
                            hex += "B";
                            break;
                        }
                        case 12: {
                            hex += "C";
                            break;
                        }
                        case 13: {
                            hex += "D";
                            break;
                        }
                        case 14: {
                            hex += "E";
                            break;
                        }
                        case 15: {
                            hex += "F";
                            break;
                        }

                        default: {
                            hex += l;
                            break;
                        }
                    }
                    decimal -= (Math.pow(16, j) * l);
                    break;
                }
            }
        }

        // Prints the hex value starting at the LSB
        for (int k = i - 1; k >= 0; k--) {
            System.out.println(hex.charAt(k));
        }

    }
}
