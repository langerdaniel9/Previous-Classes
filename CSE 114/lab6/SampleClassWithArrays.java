import java.util.Scanner;

public class SampleClassWithArrays {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter array size: ");
        int size = input.nextInt();
        input.close();

        // create an array with multiples of 10
        int[] data = multiplesOfTen(size);

        // print the content of the array
        for (int i = 0; i < size; i++)
            System.out.println(data[i]);
    }

    public static int[] multiplesOfTen(int size) {
        int[] data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = i * 10;
        return data;
    }
}
