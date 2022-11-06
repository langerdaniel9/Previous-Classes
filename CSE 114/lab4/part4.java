/*
Daniel Langer
114662901
Reverses a string and prints it
*/

import java.util.Scanner;

public class part4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter a string to reverse:");
        String string = input.next();
        String revString = "";
        input.close();
        int length = string.length();
        for (int i = length - 1; i >= 0; i--) {
            revString += string.charAt(i);

        }
        System.out.printf("%s -> %s\n", string, revString);
    }
}
