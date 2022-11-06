import java.util.Scanner;

public class PrintingDistinctNumbers {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int[] array = new int[10];
        int index = 0;
        for (int i = 0; i < 10; i++) {
            System.out.println("Enter a number");
            int next = input.nextInt();
            boolean seen = false;
            for (int number : array) {
                if (next == number) {
                    seen = true;
                }
            }
            if (!seen) {
                array[index] = next;
                index++;
            }
        }
        input.close();

        for (int j = 0; j < index; j++) {
            System.out.print(array[j] + " ");
        }
    }

}
