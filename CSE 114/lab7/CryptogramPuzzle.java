/*
* Daniel Langer
* 114662901
* Counts the occurance of letters in an input
*/

import java.util.Scanner;

public class CryptogramPuzzle {
    public static int[] count(String line) {
        int[] charArray = new int[26];

        for (int i = 0; i < line.length(); i++) {
            char ch = line.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                ch -= 'a';
                charArray[ch]++;
            }
        }

        return charArray;
    }

    public static void print(int[] charArray) {
        for (int i = 0; i < 26; i++) {
            if (charArray[i] != 0) {
                System.out.printf("%c = %d\n", (char) ('a' + i), charArray[i]);
            }
        }

    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("What is the input?");
        String line = input.nextLine().toLowerCase();
        input.close();

        int[] charArray = count(line);

        print(charArray);

    }
}
