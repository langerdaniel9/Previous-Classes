/*
 * Daniel Langer
 * 114662901
 * Enter in two matricies and multiply them
 */

import java.util.Scanner;

public class MultiplyMatricies {

    public static double[][] multiplyMatrix(double[][] a, double[][] b) {
        int a_length = a.length;
        int a_width = a[0].length;
        int b_width = b[0].length;

        double[][] product = new double[a_length][b_width];
        for (int i = 0; i < a_length; i++) {
            for (int j = 0; j < b_width; j++) {
                product[i][j] = 0;
            }
        }

        for (int i = 0; i < a_length; i++) {
            for (int j = 0; j < b_width; j++) {
                for (int y = 0; y < a_width; y++) {
                    product[i][j] += (a[i][y] * b[y][j]);
                }
            }
        }
        return product;
    }

    public static void main(String[] args) {
        double[][] a = new double[3][3];
        double[][] b = new double[3][3];

        Scanner input = new Scanner(System.in);

        System.out.println("Enter a 3x3 matrix for the multiplicand (matrix a):");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = input.nextDouble();
            }
        }

        System.out.println("Enter a 3x3 matrix for the multiplier (matrix b):");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = input.nextDouble();
            }
        }

        input.close();
        double[][] matrix = multiplyMatrix(a, b);

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
