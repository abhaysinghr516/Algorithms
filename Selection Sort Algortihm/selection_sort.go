package main

import "fmt"

func selectionSort(arr []int) {
    n := len(arr)

    for i := 0; i < n-1; i++ {
        // Find the minimum element in the unsorted portion
        minIndex := i
        for j := i + 1; j < n; j++ {
            if arr[j] < arr[minIndex] {
                minIndex = j
            }
        }

        // Swap the found minimum element with the first element in the unsorted portion
        arr[i], arr[minIndex] = arr[minIndex], arr[i]
    }
}

func main() {
    // Example unsorted slice
    unsorted := []int{64, 34, 25, 12, 22, 11, 90}

    fmt.Println("Unsorted slice:", unsorted)
    
    // Apply Selection Sort
    selectionSort(unsorted)

    fmt.Println("Sorted slice:", unsorted)
}