"""
Kadane's Algorithm Implementation in Python

Kadane's Algorithm is used to find the maximum sum of a contiguous subarray 
within a one-dimensional array of numbers in O(n) time complexity.

Time Complexity: O(n)
Space Complexity: O(1)
"""

def kadanes_algorithm(arr):
    """
    Basic Kadane's Algorithm to find maximum sum of contiguous subarray
    
    Args:
        arr (list): Input array of integers
        
    Returns:
        int: Maximum sum of contiguous subarray
    """
    if not arr:
        return 0
    
    max_so_far = float('-inf')
    max_ending_here = 0
    
    for num in arr:
        max_ending_here = max_ending_here + num
        
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
        
        if max_ending_here < 0:
            max_ending_here = 0
    
    return max_so_far

def kadanes_with_indices(arr):
    """
    Kadane's Algorithm that also returns the subarray indices
    
    Args:
        arr (list): Input array of integers
        
    Returns:
        dict: Dictionary containing max_sum, start_index, end_index, and subarray
    """
    if not arr:
        return {'max_sum': 0, 'start_index': -1, 'end_index': -1, 'subarray': []}
    
    max_so_far = float('-inf')
    max_ending_here = 0
    start = 0
    end = 0
    s = 0  # temporary start index
    
    for i, num in enumerate(arr):
        max_ending_here += num
        
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
            start = s
            end = i
        
        if max_ending_here < 0:
            max_ending_here = 0
            s = i + 1
    
    return {
        'max_sum': max_so_far,
        'start_index': start,
        'end_index': end,
        'subarray': arr[start:end + 1]
    }

def kadanes_pythonic(arr):
    """
    Pythonic implementation using built-in functions
    
    Args:
        arr (list): Input array of integers
        
    Returns:
        int: Maximum sum of contiguous subarray
    """
    if not arr:
        return 0
    
    max_so_far = float('-inf')
    max_ending_here = 0
    
    for num in arr:
        max_ending_here = max(num, max_ending_here + num)
        max_so_far = max(max_so_far, max_ending_here)
    
    return max_so_far

def kadanes_circular(arr):
    """
    Kadane's Algorithm for circular array (bonus implementation)
    
    Args:
        arr (list): Input array of integers
        
    Returns:
        int: Maximum sum of contiguous subarray in circular array
    """
    if not arr:
        return 0
    
    # Case 1: Maximum subarray is non-circular
    max_kadane = kadanes_algorithm(arr)
    
    # Case 2: Maximum subarray is circular
    # Find minimum subarray sum and subtract from total
    total_sum = sum(arr)
    
    # Invert array signs to find minimum subarray using Kadane's
    inverted_arr = [-num for num in arr]
    max_inverted = kadanes_algorithm(inverted_arr)
    min_subarray = -max_inverted
    
    max_circular = total_sum - min_subarray
    
    # If all elements are negative, return max_kadane
    return max_kadane if max_circular == 0 else max(max_kadane, max_circular)

def kadanes_all_negative_handling(arr):
    """
    Alternative implementation that handles all negative numbers explicitly
    
    Args:
        arr (list): Input array of integers
        
    Returns:
        int: Maximum sum of contiguous subarray
    """
    if not arr:
        return 0
    
    # If all numbers are negative, return the maximum single element
    if all(num < 0 for num in arr):
        return max(arr)
    
    max_so_far = 0
    max_ending_here = 0
    
    for num in arr:
        max_ending_here = max(0, max_ending_here + num)
        max_so_far = max(max_so_far, max_ending_here)
    
    return max_so_far

def print_test_case(arr, description):
    """Helper function to print test case results"""
    print(f"{description}: {arr}")
    result = kadanes_with_indices(arr)
    print(f"Maximum contiguous sum: {result['max_sum']}")
    print(f"Subarray: {result['subarray']} (indices {result['start_index']} to {result['end_index']})")
    print(f"Pythonic implementation: {kadanes_pythonic(arr)}")
    print()

def main():
    """Example usage and testing"""
    print("Kadane's Algorithm Examples:\n")
    
    # Test case 1: Mixed positive and negative numbers
    arr1 = [-2, -3, 4, -1, -2, 1, 5, -3]
    print_test_case(arr1, "Array 1 (mixed)")
    
    # Test case 2: All negative numbers
    arr2 = [-2, -3, -1, -5]
    print_test_case(arr2, "Array 2 (all negative)")
    
    # Test case 3: All positive numbers
    arr3 = [1, 2, 3, 4, 5]
    print_test_case(arr3, "Array 3 (all positive)")
    
    # Test case 4: Single element
    arr4 = [5]
    print_test_case(arr4, "Array 4 (single element)")
    
    # Test case 5: Circular array
    arr5 = [5, -3, 5]
    print(f"Array 5 (circular test): {arr5}")
    print(f"Maximum sum (linear): {kadanes_algorithm(arr5)}")
    print(f"Maximum sum (circular): {kadanes_circular(arr5)}")
    print()
    
    # Performance test with larger array
    import random
    large_arr = [random.randint(-10, 10) for _ in range(1000)]
    print(f"Large array test (1000 elements): Max sum = {kadanes_algorithm(large_arr)}")

if __name__ == "__main__":
    main()