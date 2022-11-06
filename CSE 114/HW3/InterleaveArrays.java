/*
* Daniel Langer
* 114662901
* Combines two arrays into one alternating from each
*/

public class InterleaveArrays {
    public static int[] interleave(int[] arr1, int[] arr2) {
        int totalLength = arr1.length + arr2.length;
        int arr1Len = arr1.length, arr2Len = arr2.length;
        int[] array = new int[totalLength];
        int index = 0, arr1Index = 0, arr2Index = 0;

        while (index < totalLength) {
            if (index % 2 == 0) {
                if (arr1Index == arr1Len) {
                    array[index] = arr2[arr2Index];
                    index++;
                    arr2Index++;
                    continue;
                }
                array[index] = arr1[arr1Index];
                index++;
                arr1Index++;
            } else {
                if (arr2Index == arr2Len) {
                    array[index] = arr1[arr1Index];
                    index++;
                    arr1Index++;
                    continue;
                }
                array[index] = arr2[arr2Index];
                index++;
                arr2Index++;
            }
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

    public static void main(String[] args) {
        print(interleave(new int[] { 1, 3, 5 }, new int[] { 2, 4, 6 }));
        // should return [1, 2, 3, 4, 5, 6]
        print(interleave(new int[] { 10, 20, 30, 40, 50, 60, 70, 80 }, new int[] { 2, 4, 6, 8 }));
        // should return [10, 2, 20, 4, 30, 6, 40, 8, 50, 60, 70, 80]
        print(interleave(new int[] { 1, 3, 5 }, new int[] { 2, 4, 6, 8, 10 }));
        // should return [1, 2, 3, 4, 5, 6, 8, 10]
        print(interleave(new int[] { 2, 4, 6, 8, 10, 12, 14, 16, 18 }, new int[] { 1, 2, 3 }));
        // should return [2, 1, 4, 2, 6, 3, 8, 10, 12, 14, 16, 18]
        print(interleave(new int[] {}, new int[] { 1, 2, 3 }));
        // should return [1, 2, 3]
    }
}
