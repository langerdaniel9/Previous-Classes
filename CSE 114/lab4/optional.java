import java.util.Scanner;

public class optional {
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

        System.out.printf("1 = %d 2 = %d\n", string.length(), revString.length());
        for (int j = 0; j < string.length(); j++) {
            System.out.printf("%c %c\n", string.charAt(j), revString.charAt(j));
        }

        String one = "opopo";
        String two = "opopo";

        if (string == revString) {
            System.out.println("Palindrome");
        } else {
            System.out.println("Not a palindrome");
        }
    }
}
