package main

import "fmt"

func binarySearch(arr []int, x int) int {
    left := 0
    right := len(arr) - 1

    for left <= right {
        mid := left + (right - left) / 2

        if arr[mid] == x {
            return mid
        } else if arr[mid] < x {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return -1
}

func main() {
    arr := []int{2, 3, 4, 10, 40}
    x := 10

    result := binarySearch(arr, x)
    if result != -1 {
        fmt.Println("Element found at index", result)
    } else {
        fmt.Println("Element not found in the array")
    }
}
