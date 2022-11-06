/* 
Daniel Langer
114662901
Creates an n x m matrix and calculates the sum of all the columns
*/

import java.util.Scanner;

public class SumColumn {

    public static void sumColumn(int[][] array, int column) {
        int row = array.length;
        System.out.println("\nThe sums of the columns are:");
        for (int i = 0; i < column; i++) {
            int sum = 0;
            for (int j = 0; j < row; j++) {
                sum += array[j][i];
            }
            System.out.print(sum + " ");
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("What are the dimensions of the matrix? (row x column)");
        int row = input.nextInt();
        int column = input.nextInt();
        int[][] array = new int[row][column];
        System.out.println("What are the elements of the " + row + " x " + column + " matrix?");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                array[i][j] = input.nextInt();
            }
        }
        input.close();

        sumColumn(array, column);

    }
}
