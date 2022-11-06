/*
 * Daniel Langer
 * 11462901
 */

public class RecursiveBackwardsPrint {
    public static void reverseDisplay(int value) {
        String toDisplay = Integer.toString(value);
        if (toDisplay.length() == 1) {
            System.out.print(toDisplay.charAt(toDisplay.length() - 1));
            return;
        }
        String subString = toDisplay.substring(0, toDisplay.length() - 1);
        System.out.print(toDisplay.charAt(toDisplay.length() - 1));
        reverseDisplay(Integer.parseInt(subString));
    }

    public static void main(String[] args) {
        reverseDisplay(12345);
    }
}
