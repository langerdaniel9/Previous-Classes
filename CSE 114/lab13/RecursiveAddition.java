/*
 * Daniel Langer
 * 11462901
 */

public class RecursiveAddition {
    public static double formula(int i) {
        if (i == 1) {
            return 1;
        }
        return ((1.0 / i) + formula(i - 1));
    }

    public static void main(String[] args) {
        for (int i = 1; i <= 10; i++) {
            System.out.println("The result for i = " + i + " is: " + formula(i));
        }
    }
}
