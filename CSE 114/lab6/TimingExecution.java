import java.util.Scanner;
import java.util.Random;

public class TimingExecution {
    static int size = 1000000;
    static Random rand = new Random();

    /** Use linear search to find the key in the list */
    public static int linearSearch(int[] list, int key) {
        for (int i = 0; i < list.length; i++)
            if (key == list[i])
                return i;
        return -1;
    }

    /** Use binary search to find the key in the list */
    public static int binarySearch(int[] list, int key) {
        int low = 0;
        int high = list.length - 1;
        int mid;
        while (high >= low) {
            mid = (low + high) / 2;
            if (key < list[mid])
                high = mid - 1;
            else if (key == list[mid])
                return mid;
            else
                low = mid + 1;
        }
        return -1 - low;
    }

    /** A selectionSort method for sorting numbers */
    public static void selectionSort(double[] list) {
        for (int i = 0; i < list.length; i++) {
            // Find the minimum in the list[i..list.length-1]
            double currentMin = list[i];
            int currentMinIndex = i;
            for (int j = i + 1; j < list.length; j++) {
                if (currentMin > list[j]) {
                    currentMin = list[j];
                    currentMinIndex = j;
                }
            }
            // Swap list[i] with list[currentMinIndex] if necessary;
            if (currentMinIndex != i) {
                list[currentMinIndex] = list[i];
                list[i] = currentMin;
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("What is the upper range?");
        int upRange = input.nextInt();
        input.close();

        int[] data = random(upRange);

        int key = rand.nextInt(upRange) + 1;

        long startLS = System.nanoTime();
        linearSearch(data, key);
        long endLS = System.nanoTime();
        long executionTimeLS = endLS - startLS;

        long startBS = System.nanoTime();
        linearSearch(data, key);
        long endBS = System.nanoTime();
        long executionTimeBS = endBS - startBS;

        long startSS = System.nanoTime();
        linearSearch(data, key);
        long endSS = System.nanoTime();
        long executionTimeSS = endSS - startSS;

        System.out.println("LS = " + executionTimeLS + " BS = " + executionTimeBS + " SS = " + executionTimeSS);
    }

    public static int[] random(int upRange) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            int rand1 = rand.nextInt(upRange) + 1;
            array[i] = rand1;
        }
        return array;
    }
}
