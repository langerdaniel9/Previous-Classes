/*
* Daniel Langer
* 114662901
* Various array functions, create random arrays, print arrays, find sums of array, find first occurance of a value, count number of multiples of a number in an array
*/

public class ArrayUtils {
    public static int[] randomArray(int arraySize, int upperRange) {
        int[] array = new int[arraySize];

        for (int i = 0; i < arraySize; i++) {
            array[i] = (int) Math.floor(Math.random() * (upperRange));
        }
        return array;
    }

    public static void print(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.print(array[array.length - 1]);
        System.out.print("]\n");
    }

    public static int arraySum(int[] array) {
        int sum = 0;

        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        return sum;
    }

    public static int contains(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static int countMultiplesOf(int[] array, int num) {
        int count = 0;
        for (int element : array) {
            if (element % num == 0 && element != 0) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] randArray = randomArray(100, 21);
        System.out.println("The array is :");
        print(randArray);
        int sum = arraySum(randArray);
        System.out.printf("The average of the array is %f, since the sum is %d and there are %d elements\n",
                (sum * 1.0) / randArray.length, sum, randArray.length);

        System.out.println("There is an occurance of 12 at index " + contains(randArray, 12));
        System.out.println("There are " + countMultiplesOf(randArray, 7) + " multiples of 7 in the array");
    }
}
