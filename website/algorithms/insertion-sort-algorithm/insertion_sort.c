#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    
    // Start from the second element (index 1)
    for (i = 1; i < n; i++) {
        key = arr[i];  // Current element to be inserted
        j = i - 1;     // Last element of sorted portion
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place key at its correct position
        arr[j + 1] = key;
    }
}

// Function to perform insertion sort in descending order
void insertionSortDescending(int arr[], int n) {
    int i, key, j;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // For descending order, check if arr[j] < key
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Recursive implementation of insertion sort
void insertionSortRecursive(int arr[], int n) {
    // Base case
    if (n <= 1)
        return;
    
    // Sort first n-1 elements
    insertionSortRecursive(arr, n - 1);
    
    // Insert last element at its correct position in sorted array
    int last = arr[n - 1];
    int j = n - 2;
    
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Simple main function for basic usage
int main() {
    printf("=== INSERTION SORT IMPLEMENTATION ===\n\n");
    
    // Example array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    printf("Sorted array:   ");
    printArray(arr, n);
    
    return 0;
}
