/* 
Daniel Langer
114662901
Random 8 x 8 checkerboard that finds rows/columns/diagonals that are all 0's or all 1's
*/

public class RandomCheckerboard {

    public static int[][] createArray() {

        int[][] array = new int[8][8];

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                array[i][j] = (int) Math.round(Math.random());
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(array[i][j]);
            }
            System.out.println();
        }

        return array;
    }

    public static void check(int[][] array) {
        // Check diagonals
        for (int k = 0; k < 2; k++) {
            int[] count = { 0, 0 };
            if (k == 0) { // negative sloped diagonal
                for (int i = 0; i < 8; i++) {
                    count[array[i][i]]++;
                }
                if (count[0] == 8) {
                    System.out.println("The negative sloped diagonal has all 0's");
                } else if (count[1] == 8) {
                    System.out.println("The negative sloped diagonal has all 1's");
                }
            } else { // positive sloped diagonal

                for (int i = 0, j = 7; i < 8; i++, j--) {
                    count[array[i][j]]++;
                }
                if (count[0] == 8) {
                    System.out.println("The positive sloped diagonal has all 0's");
                } else if (count[1] == 8) {
                    System.out.println("The positive sloped diagonal has all 1's");
                }
            }
        }

        // Check rows

        for (int i = 0; i < 8; i++) {
            int[] count = { 0, 0 };
            for (int j = 0; j < 8; j++) {
                count[array[i][j]]++;
            }
            if (count[0] == 8) {
                System.out.println("The " + i + "'th row is all 0's");
            } else if (count[1] == 8) {
                System.out.println("The " + i + "'th row is all 1's");
            }
        }

        // Check columns
        for (int i = 0; i < 8; i++) {
            int[] count = { 0, 0 };
            for (int j = 0; j < 8; j++) {
                count[array[j][i]]++;
            }
            if (count[0] == 8) {
                System.out.println("The " + i + "'th column is all 0's");
            } else if (count[1] == 8) {
                System.out.println("The " + i + "'th column is all 1's");
            }
        }
    }

    public static void main(String[] args) {
        int[][] array = createArray();
        check(array);
    }
}
