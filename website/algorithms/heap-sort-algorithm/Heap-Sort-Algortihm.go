package main

import "fmt"

func swap(a *int, b *int) {
	tmp := *a
	*a = *b
	*b = tmp
}

func heapify(arr []int, n int, i int) {
	largest := i
	left := 2*i + 1
	right := 2*i + 2

	if left < n && arr[left] > arr[largest] {
		largest = left
	}

	if right < n && arr[right] > arr[largest] {
		largest = right
	}

	if largest != i {
		swap(&arr[i], &arr[largest])
		heapify(arr, n, largest)
	}
}

func heapSort(arr []int) {
	n := len(arr)

	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i)
	}

	for i := n - 1; i > 0; i-- {
		swap(&arr[0], &arr[i])
		heapify(arr, i, 0)
	}
}

func main() {
	arr := []int{12, 11, 13, 5, 6, 7}

	heapSort(arr)

	for _, val := range arr {
		fmt.Print(val, " ")
	}
	fmt.Println()
}
