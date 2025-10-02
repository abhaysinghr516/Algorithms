   # Sort array by a specific digit position(ones ,tens,hundreds,etc.)
def countingSort(arr, digit_position):
    size = len(arr)
    sorted_arr = [0] * size  # Temporary array to store sorted numbers
    count = [0] * 10     
    
   # Count occurrence of each digit
    for num in arr:
        digit = (num // digit_position) % 10  # Extract the digit at current position
        count[digit] += 1
    
   # Accumulating the counts
    for i in range(1, 10):
        count[i] += count[i - 1]
    
   # Place elements in sorted order
    i = size - 1
    while i >= 0:
        index = arr[i] // digit_position
        digit = index % 10  
        sorted_arr[count[digit] - 1] = arr[i] 
        count[digit] -= 1  
        i -= 1

   # Copy back to original array
    for i in range(size):
        arr[i] = sorted_arr[i]

   # Sort array by using Radix Sort - sorts digit by digit from right to left
def radixSort(arr):
    max_element = max(arr)
    digit_position = 1 
    while max_element // digit_position > 0:
        countingSort(arr, digit_position)
        digit_position *= 10  # Move to next digit position


# Example usage
arr = [200, 500, 125, 2, 35, 128]
print("Original array:", arr)
radixSort(arr)
print("Sorted array:", arr)