public class numberSystems {
    public static String decimal2hex(int decimal) {
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
                    if (l > 9) {
                        hex += (char) (65 + (l - 10));
                    } else {
                        hex += l;
                    }
                    decimal -= (Math.pow(16, j) * l);
                    break;
                }
            }
        }
        return hex;
    }

    public static String decimal2BaseX(int decimal, int base) {
        String result = "";
        int i = 0;

        // Finds the number of digits in the hex value
        while (Math.pow(base, i) <= decimal) {
            i++;
        }

        // Finds the hex value starting at the largest possible digit
        for (int j = i - 1; j >= 0; j--) {
            for (int l = (base - 1); l >= 0; l--) {
                if (decimal - (Math.pow(base, j) * l) >= 0) {
                    if (l > 9) {
                        result += (char) (65 + (l - 10));

                    } else {
                        result += l;
                    }
                    decimal -= (Math.pow(base, j) * l);
                    break;
                }
            }
        }
        return result;
    } // base is less than 9

    public static void main(String[] args) {
        System.out.println(decimal2hex(161)); // A1
        System.out.println(decimal2BaseX(6, 2)); // 110
        System.out.println(decimal2BaseX(87, 8)); // 127
    }
}
