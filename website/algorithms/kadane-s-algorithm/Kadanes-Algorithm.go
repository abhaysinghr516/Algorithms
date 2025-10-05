/*
Kadane's Algorithm Implementation in Go

Kadane's Algorithm is used to find the maximum sum of a contiguous subarray 
within a one-dimensional array of numbers in O(n) time complexity.

Time Complexity: O(n)
Space Complexity: O(1)
*/

package main

import (
	"fmt"
	"math"
)

// KadanesAlgorithm finds the maximum sum of contiguous subarray
func KadanesAlgorithm(arr []int) int {
	if len(arr) == 0 {
		return 0
	}

	maxSoFar := math.MinInt32
	maxEndingHere := 0

	for _, num := range arr {
		maxEndingHere = maxEndingHere + num

		if maxSoFar < maxEndingHere {
			maxSoFar = maxEndingHere
		}

		if maxEndingHere < 0 {
			maxEndingHere = 0
		}
	}

	return maxSoFar
}

// SubarrayResult represents the result of Kadane's algorithm with indices
type SubarrayResult struct {
	MaxSum     int
	StartIndex int
	EndIndex   int
	Subarray   []int
}

// KadanesWithIndices returns maximum sum along with subarray indices
func KadanesWithIndices(arr []int) SubarrayResult {
	if len(arr) == 0 {
		return SubarrayResult{MaxSum: 0, StartIndex: -1, EndIndex: -1, Subarray: []int{}}
	}

	maxSoFar := math.MinInt32
	maxEndingHere := 0
	start := 0
	end := 0
	s := 0 // temporary start index

	for i, num := range arr {
		maxEndingHere += num

		if maxSoFar < maxEndingHere {
			maxSoFar = maxEndingHere
			start = s
			end = i
		}

		if maxEndingHere < 0 {
			maxEndingHere = 0
			s = i + 1
		}
	}

	// Create subarray slice
	subarray := make([]int, end-start+1)
	copy(subarray, arr[start:end+1])

	return SubarrayResult{
		MaxSum:     maxSoFar,
		StartIndex: start,
		EndIndex:   end,
		Subarray:   subarray,
	}
}

// KadanesAlternative is an alternative implementation
func KadanesAlternative(arr []int) int {
	if len(arr) == 0 {
		return 0
	}

	maxSoFar := math.MinInt32
	maxEndingHere := 0

	for _, num := range arr {
		maxEndingHere = max(num, maxEndingHere+num)
		maxSoFar = max(maxSoFar, maxEndingHere)
	}

	return maxSoFar
}

// KadanesCircular finds maximum sum in circular array
func KadanesCircular(arr []int) int {
	if len(arr) == 0 {
		return 0
	}

	// Case 1: Maximum subarray is non-circular
	maxKadane := KadanesAlgorithm(arr)

	// Case 2: Maximum subarray is circular
	// Find minimum subarray sum and subtract from total
	totalSum := 0
	for _, num := range arr {
		totalSum += num
	}

	// Invert array signs to find minimum subarray using Kadane's
	invertedArr := make([]int, len(arr))
	for i, num := range arr {
		invertedArr[i] = -num
	}

	maxInverted := KadanesAlgorithm(invertedArr)
	minSubarray := -maxInverted
	maxCircular := totalSum - minSubarray

	// If all elements are negative, return maxKadane
	if maxCircular == 0 {
		return maxKadane
	}

	return max(maxKadane, maxCircular)
}

// Helper function for maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function for minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// PrintArray prints an array in a formatted way
func PrintArray(arr []int) {
	fmt.Print("[")
	for i, num := range arr {
		if i > 0 {
			fmt.Print(", ")
		}
		fmt.Print(num)
	}
	fmt.Print("]")
}

// PrintTestCase prints a formatted test case
func PrintTestCase(arr []int, description string) {
	fmt.Printf("%s: ", description)
	PrintArray(arr)
	fmt.Println()

	result := KadanesWithIndices(arr)
	fmt.Printf("Maximum contiguous sum: %d\n", result.MaxSum)
	fmt.Printf("Subarray: ")
	PrintArray(result.Subarray)
	fmt.Printf(" (indices %d to %d)\n", result.StartIndex, result.EndIndex)
	fmt.Printf("Alternative implementation: %d\n\n", KadanesAlternative(arr))
}

func main() {
	fmt.Println("Kadane's Algorithm Examples:\n")

	// Test case 1: Mixed positive and negative numbers
	arr1 := []int{-2, -3, 4, -1, -2, 1, 5, -3}
	PrintTestCase(arr1, "Array 1 (mixed)")

	// Test case 2: All negative numbers
	arr2 := []int{-2, -3, -1, -5}
	PrintTestCase(arr2, "Array 2 (all negative)")

	// Test case 3: All positive numbers
	arr3 := []int{1, 2, 3, 4, 5}
	PrintTestCase(arr3, "Array 3 (all positive)")

	// Test case 4: Single element
	arr4 := []int{5}
	PrintTestCase(arr4, "Array 4 (single element)")

	// Test case 5: Circular array
	arr5 := []int{5, -3, 5}
	fmt.Printf("Array 5 (circular test): ")
	PrintArray(arr5)
	fmt.Println()
	fmt.Printf("Maximum sum (linear): %d\n", KadanesAlgorithm(arr5))
	fmt.Printf("Maximum sum (circular): %d\n\n", KadanesCircular(arr5))

	// Edge case: Empty array
	arr6 := []int{}
	fmt.Printf("Empty array: ")
	PrintArray(arr6)
	fmt.Printf(" -> Maximum sum: %d\n", KadanesAlgorithm(arr6))
}