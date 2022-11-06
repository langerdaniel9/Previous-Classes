/*
 * Daniel Langer
 * 114662901
 * Tic Tac Toe game with adjustable grid size
 */

import java.util.Scanner;

public class TicTacToe {

    public static int GRID_SIZE = 3;
    public static boolean finished = false;

    public static void check(char[][] array) {
        // Check diagonals
        for (int k = 0; k < 2; k++) {
            int[] count = { 0, 0 }; // first one is X, second is O
            if (k == 0) { // negative sloped diagonal
                for (int i = 0; i < GRID_SIZE; i++) {
                    if (array[i][i] == 'X') {
                        count[0]++;
                    } else if (array[i][i] == 'O') {
                        count[1]++;
                    }
                }
                if (count[0] == GRID_SIZE) {
                    finished = true;
                    print(array);
                    System.out.println("Player 2 (X) is the winner!");
                } else if (count[1] == GRID_SIZE) {
                    finished = true;
                    print(array);
                    System.out.println("Player 1 (O) is the winner!");
                }
            } else { // positive sloped diagonal

                for (int i = 0, j = GRID_SIZE - 1; i < GRID_SIZE; i++, j--) {
                    if (array[i][j] == 'X') {
                        count[0]++;
                    } else if (array[i][j] == 'O') {
                        count[1]++;
                    }
                }
                if (count[0] == GRID_SIZE) {
                    finished = true;
                    print(array);
                    System.out.println("Player 2 (X) is the winner!");
                } else if (count[1] == GRID_SIZE) {
                    finished = true;
                    print(array);
                    System.out.println("Player 1 (O) is the winner!");
                }
            }
        }

        // Check rows

        for (int i = 0; i < GRID_SIZE; i++) {
            int[] count = { 0, 0 };
            for (int j = 0; j < GRID_SIZE; j++) {
                if (array[i][j] == 'X') {
                    count[0]++;
                } else if (array[i][j] == 'O') {
                    count[1]++;
                }
            }
            if (count[0] == GRID_SIZE) {
                finished = true;
                print(array);
                System.out.println("Player 2 (X) is the winner!");
            } else if (count[1] == GRID_SIZE) {
                finished = true;
                print(array);
                System.out.println("Player 1 (O) is the winner!");
            }
        }

        // Check columns
        for (int i = 0; i < GRID_SIZE; i++) {
            int[] count = { 0, 0 };
            for (int j = 0; j < GRID_SIZE; j++) {
                if (array[j][i] == 'X') {
                    count[0]++;
                } else if (array[j][i] == 'O') {
                    count[1]++;
                }
            }
            if (count[0] == GRID_SIZE) {
                finished = true;
                print(array);
                System.out.println("Player 2 (X) is the winner!");
            } else if (count[1] == GRID_SIZE) {
                finished = true;
                print(array);
                System.out.println("Player 1 (O) is the winner!");
            }
        }
    }

    public static void print(char[][] grid) {
        for (int i = 0; i < GRID_SIZE; i++) {
            System.out.print('|');
            for (int j = 0; j < GRID_SIZE; j++) {
                System.out.printf(" %c |", grid[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        char[][] grid = new char[GRID_SIZE][GRID_SIZE];
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = ' ';
            }
        }

        Scanner input = new Scanner(System.in);
        int count = 1;

        while (count < 10 && !finished) {
            if (count % 2 == 1) { // Player 1's turn
                print(grid);
                System.out.println("What position to place an O? Enter in (row) (column) format.");
                int row = input.nextInt() - 1;
                int column = input.nextInt() - 1;
                while (row > GRID_SIZE || column > GRID_SIZE) {
                    System.out.println("That position is out of bounds, try a different position:");
                    System.out.println("What position to place an O? Enter in (row) (column) format.");
                    row = input.nextInt() - 1;
                    column = input.nextInt() - 1;
                }
                while (grid[row][column] != ' ') {
                    System.out.println("That position is already taken, try a different position:");
                    System.out.println("What position to place an O? Enter in (row) (column) format.");
                    row = input.nextInt() - 1;
                    column = input.nextInt() - 1;
                }
                grid[row][column] = 'O';
                count++;
                check(grid);
            } else { // Player 2's turn
                print(grid);
                System.out.println("What position to place an X? Enter in (row) (column) format.");
                int row = input.nextInt() - 1;
                int column = input.nextInt() - 1;
                while (row > GRID_SIZE || column > GRID_SIZE) {
                    System.out.println("That position is out of bounds, try a different position:");
                    System.out.println("What position to place an X? Enter in (row) (column) format.");
                    row = input.nextInt() - 1;
                    column = input.nextInt() - 1;
                }
                while (grid[row][column] != ' ') {
                    System.out.println("That position is already taken, try a different position:");
                    System.out.println("What position to place an X? Enter in (row) (column) format.");
                    row = input.nextInt() - 1;
                    column = input.nextInt() - 1;
                }
                grid[row][column] = 'X';
                count++;
                check(grid);
            }
        }
        if (!finished) {
            print(grid);
            System.out.println("The game is a draw!");
        }
        input.close();
    }
}