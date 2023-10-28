package BubbleSortAlgorithm;

import java.util.Arrays;

public class BubbleSort {

    public static void main(String[] args) {
        int[] arr = {18, 12, 19, 18, 29, 89, 98};
        bubbleSort(arr);
        System.out.println("After Sorting the Integer Array: " + Arrays.toString(arr));
    }

    public static void bubbleSort(int[] arr) {
        boolean swap;
        for (int i = 0; i < arr.length - 1; i++) {
            swap = false;
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap = true;
                }
            }
            if (!swap) {
                break;
            }
        }
    }
}
