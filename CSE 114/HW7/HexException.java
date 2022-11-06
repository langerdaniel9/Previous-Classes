/*
 * Daniel Langer
 * 114662901
 */

class HexFormatException extends java.lang.NumberFormatException {
    public HexFormatException() {
        super("The string is not a hex string");
    }
}

public class HexException {
    public static int parseHex(String in) throws HexFormatException {
        // Checks if the input string is valid
        in = in.toUpperCase();
        char[] allowed = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
        for (int i = 0; i < in.length(); i++) {
            boolean match = false;
            for (char c : allowed) {
                if (in.charAt(i) == c) {
                    match = true;
                    break;
                }
            }
            if (!match) {
                throw new HexFormatException();
            }
        }
        // Calculate and return result
        int result = 0;
        int exponent = 0;
        for (int i = (in.length() - 1); i >= 0; i--) {
            char current = in.charAt(i);
            int currentInt;
            if (current >= '0' && current <= '9') {
                currentInt = ((int) current - '0');
            } else {
                currentInt = ((int) (current - 'A')) + 10;
            }
            result += Math.pow(16, exponent) * currentInt;
            exponent++;
        }
        return result;
    }

    public static void main(String[] args) {
        try {
            System.out.println(parseHex("ABCE2"));
            System.out.println(parseHex("ABCY2"));
        } catch (HexFormatException e) {
            System.out.println(e);
        }
    }
}
