# Radix Sort Algorithm

Radix Sort is a non-comparative sorting algorithm that sorts integers by processing them digit by digit. It works by repeatedly distributing elements into groups based on each digit's value, starting from the least significant digit to the most significant digit.

## Time Complexity

Best: O(n * d)
Average: O(n * d)
Worst: O(n * d)

Where:
- d = number of digits in the maximum element
- n = number of elements

## Space Complexity

O(n + k)

Where:
- n = number of elements
- k = range of digit (10 for decimal numbers)

## Example Use Case

Sorting large datasets of integers or strings with fixed-length keys, especially when the range of values is known and the number of digits is relatively small. Radix Sort is particularly efficient for sorting numbers, dates, or any data that can be represented with fixed-size keys.
When  Memory is limited or the number of digits is very large avoid using Radix Sort. 

