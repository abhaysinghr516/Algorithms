/*
 * Kadane's Algorithm Implementation in C
 * 
 * Kadane's Algorithm is used to find the maximum sum of a contiguous subarray 
 * within a one-dimensional array of numbers in O(n) time complexity.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <limits.h>

// Function to find maximum sum of contiguous subarray
int kadanesAlgorithm(int arr[], int n) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < n; i++) {
        maxEndingHere = maxEndingHere + arr[i];
        
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
        
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    
    return maxSoFar;
}

// Function to find maximum sum and return the subarray indices
int kadanesWithIndices(int arr[], int n, int* start, int* end) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    int s = 0; // temporary start index
    
    *start = 0;
    *end = 0;
    
    for (int i = 0; i < n; i++) {
        maxEndingHere += arr[i];
        
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            *start = s;
            *end = i;
        }
        
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
            s = i + 1;
        }
    }
    
    return maxSoFar;
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1: Mixed positive and negative numbers
    int arr1[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Array 1: ");
    printArray(arr1, n1);
    printf("Maximum contiguous sum: %d\n\n", kadanesAlgorithm(arr1, n1));
    
    // Test case 2: All negative numbers
    int arr2[] = {-2, -3, -1, -5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Array 2: ");
    printArray(arr2, n2);
    printf("Maximum contiguous sum: %d\n\n", kadanesAlgorithm(arr2, n2));
    
    // Test case 3: All positive numbers
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Array 3: ");
    printArray(arr3, n3);
    printf("Maximum contiguous sum: %d\n\n", kadanesAlgorithm(arr3, n3));
    
    // Test case with indices
    int start, end;
    int maxSum = kadanesWithIndices(arr1, n1, &start, &end);
    
    printf("Maximum sum subarray in Array 1:\n");
    printf("Sum: %d, Start index: %d, End index: %d\n", maxSum, start, end);
    printf("Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    return 0;
}