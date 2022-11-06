/*
 * Daniel Langer
 * 11462901
 */

public class RecursiveBackwardsReturn {
    public static int reverseReturn(int value) {
        String toDisplay = Integer.toString(value);
        if (toDisplay.length() == 1) {
            return Integer.parseInt(Character.toString(toDisplay.charAt(toDisplay.length() - 1)));
        }
        String subString = toDisplay.substring(0, toDisplay.length() - 1);
        return Integer.parseInt(Character.toString(toDisplay.charAt(toDisplay.length() - 1))
                + Integer.toString((reverseReturn(Integer.parseInt(subString)))));
    }

    public static void main(String[] args) {
        System.out.println(reverseReturn(12345));
    }
}
