/*
* Daniel Langer
* 114662901
* Takes in a 10 numbers and only saves distinct numbers
*/

import java.util.Scanner;

public class PrintingDistinctNumbers {
    public static boolean linearSearch(int[] list, int key, int count) {
        for (int i = 0; i < count; i++)
            if (key == list[i])
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int[] array = new int[10];
        int index = 0;
        System.out.println("Enter 10 numbers");
        for (int i = 0; i < 10; i++) {
            int next = input.nextInt();
            if (linearSearch(array, next, index)) {
                array[index] = next;
                index++;
            }
        }
        input.close();
        System.out.println("\nDistinct Numbers:");
        for (int j = 0; j < index; j++) {
            System.out.println(array[j]);
        }
    }
}
