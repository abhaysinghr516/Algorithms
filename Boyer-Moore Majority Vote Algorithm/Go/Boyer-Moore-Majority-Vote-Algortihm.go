package main

import "fmt"

func find_majority_element(arr []int) int {
    candidate := 0
    count := 0

    for _, num := range arr {
        if count == 0 {
            candidate = num
        }
        if num == candidate {
            count++
        } else {
            count--
        }
    }

    return candidate
}

func main() {
    arr := []int{2, 2, 1, 1, 2, 2}

    result := find_majority_element(arr)
    fmt.Println("Majority element is:", result)
}
