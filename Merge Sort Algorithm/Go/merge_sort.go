package main

import "fmt"

func mergeSort(arr []int) []int {
   if len(arr) <= 1 {
      return arr
   }
   middle := len(arr) / 2
   left := mergeSort(arr[:middle])
   right := mergeSort(arr[middle:])
   return merge(left, right)
}

func merge(left, right []int) []int {
   result := make([]int, len(left)+len(right))
   i, j := 0, 0
   for k := 0; k < len(result); k++ {
      if i >= len(left) {
         result[k] = right[j]
         j++
      } else if j >= len(right) {
         result[k] = left[i]
         i++
      } else if left[i] < right[j] {
         result[k] = left[i]
         i++
      } else {
         result[k] = right[j]
         j++
      }
   }
   return result
}

func main() {
   arr := []int{5, 2, 6, 3, 1, 4}
   fmt.Println("The given unsorted array is:", arr)
   sorted := mergeSort(arr)
   fmt.Println("The sorted array is:", sorted)
}