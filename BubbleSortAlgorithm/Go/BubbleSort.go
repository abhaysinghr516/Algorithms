package main

import (
	"fmt"
)

/*
Bubble Sort Implimentation in Go

Time Complexity O(n^2)
*/
func main() {
	var arr = []int{24, 9, 15, 1, 4, 8, 6}
	fmt.Println("Before sort: ", arr)
	bubbleSort(arr)
	fmt.Println("After sort: ", arr)
}

func bubbleSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := 1; j < len(arr)-i; j++ {
			if arr[j-1] > arr[j] {
				swap(arr, j-1, j)
			}
		}
	}
}

func swap(arr []int, i, j int) {
	var temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp
 
