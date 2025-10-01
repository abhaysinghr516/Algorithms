# Radix Sort Algorithm

Radix Sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by individual digits that share the same significant position and value. It processes digits from least significant digit (LSD) to most significant digit (MSD) or vice versa.

## Algorithm Overview

Radix Sort works by sorting the input numbers digit by digit, starting from the least significant digit to the most significant digit. It uses a stable sorting algorithm (like Counting Sort) as a subroutine to sort the array according to each digit.

### Steps:
1. Find the maximum number to determine the number of digits
2. For each digit position (from least to most significant):
   - Use counting sort to sort elements based on current digit
   - Update the array with the sorted result
3. Repeat until all digits are processed

## Time Complexity

- **Best**: O(d × (n + k))
- **Average**: O(d × (n + k))
- **Worst**: O(d × (n + k))

Where:
- n = number of elements
- d = number of digits in the maximum number
- k = range of digits (0-9 for decimal)

## Space Complexity

O(n + k) - for the counting array and output array

## Example Use Case

- **Sorting large datasets of integers**: When dealing with large numbers of integers with a fixed number of digits
- **Database sorting**: Sorting records by numeric keys
- **Distributed systems**: When comparison-based sorting is expensive
- **Graphics processing**: Sorting pixels by color values

## Code Snippet

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get maximum value in array
int getMax(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Counting sort for a specific digit position
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);
    
    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Calculate cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy output array to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main radix sort function
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    
    // Do counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}
```

## Algorithm Characteristics

- **Stable**: Yes (maintains relative order of equal elements)
- **In-place**: No (requires additional space)
- **Adaptive**: No (always takes the same time regardless of input)
- **Online**: No (needs to know all elements beforehand)