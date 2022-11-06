/*
* Daniel Langer
* 114662901
* Eliminates duplicate characters from a string
*/

// import java.util.Scanner;

public class EliminateDuplicates {

    public static String eD(String line) {
        char[] charArray = new char[95];
        int index = 0;
        String newString = "";

        for (int i = 0; i < line.length(); i++) {
            boolean seen = false;
            for (char ch : charArray) {
                if (line.charAt(i) == ch) {
                    seen = true;
                }
            }

            charArray[index] = line.charAt(i);
            index++;

            if (!seen) {
                newString += line.charAt(i);
            }
        }

        return newString;
    }

    public static void main(String[] args) {
        /*
         * Scanner input = new Scanner(System.in);
         * System.out.println("What is the input?");
         * String line = input.nextLine();
         * input.close();
         */

        System.out.printf("\'%s\' returns \'%s\'\n", "abracadabra", eD("abracadabra"));
        System.out.printf("\'%s\' returns \'%s\'\n", "Stony Brook University", eD("Stony Brook University"));
        System.out.printf("\'%s\' returns \'%s\'\n", "This is a test sentence.", eD("This is a test sentence."));
        System.out.printf("\'%s\' returns \'%s\'\n", "hello friends sell fiend", eD("hello friends sell fiend"));
        System.out.printf("\'%s\' returns \'%s\'\n", "mississippi", eD("mississippi"));
    }
}
