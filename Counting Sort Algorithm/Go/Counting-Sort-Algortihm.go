package main

import (
	"fmt"
)

func counting_sort(arr []int) {
	max, min := arr[0], arr[0]

	for _, num := range arr {
		if num > max {
			max = num
		}
		if num < min {
			min = num
		}
	}

	rangeLen := max - min + 1
	count := make([]int, rangeLen)
	output := make([]int, len(arr))

	for _, num := range arr {
		count[num-min]++
	}

	for i := 1; i < rangeLen; i++ {
		count[i] += count[i-1]
	}

	for i := len(arr) - 1; i >= 0; i-- {
		output[count[arr[i]-min]-1] = arr[i]
		count[arr[i]-min]--
	}

	copy(arr, output)
}

func main() {
	arr := []int{4, 2, 2, 8, 3, 3, 1}

	counting_sort(arr)

	for _, num := range arr {
		fmt.Printf("%d ", num)
	}
}
