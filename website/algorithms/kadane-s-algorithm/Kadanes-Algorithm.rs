/*
Kadane's Algorithm Implementation in Rust

Kadane's Algorithm is used to find the maximum sum of a contiguous subarray 
within a one-dimensional array of numbers in O(n) time complexity.

Time Complexity: O(n)
Space Complexity: O(1)
*/

use std::cmp;

/// Basic Kadane's Algorithm to find maximum sum of contiguous subarray
pub fn kadanes_algorithm(arr: &[i32]) -> i32 {
    if arr.is_empty() {
        return 0;
    }

    let mut max_so_far = i32::MIN;
    let mut max_ending_here = 0;

    for &num in arr {
        max_ending_here = max_ending_here + num;

        if max_so_far < max_ending_here {
            max_so_far = max_ending_here;
        }

        if max_ending_here < 0 {
            max_ending_here = 0;
        }
    }

    max_so_far
}

/// Result structure for Kadane's algorithm with indices
#[derive(Debug, Clone)]
pub struct SubarrayResult {
    pub max_sum: i32,
    pub start_index: usize,
    pub end_index: usize,
    pub subarray: Vec<i32>,
}

/// Kadane's Algorithm that also returns the subarray indices
pub fn kadanes_with_indices(arr: &[i32]) -> Option<SubarrayResult> {
    if arr.is_empty() {
        return None;
    }

    let mut max_so_far = i32::MIN;
    let mut max_ending_here = 0;
    let mut start = 0;
    let mut end = 0;
    let mut s = 0; // temporary start index

    for (i, &num) in arr.iter().enumerate() {
        max_ending_here += num;

        if max_so_far < max_ending_here {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if max_ending_here < 0 {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    Some(SubarrayResult {
        max_sum: max_so_far,
        start_index: start,
        end_index: end,
        subarray: arr[start..=end].to_vec(),
    })
}

/// Alternative implementation using iterator methods
pub fn kadanes_functional(arr: &[i32]) -> i32 {
    if arr.is_empty() {
        return 0;
    }

    let mut max_so_far = i32::MIN;
    let mut max_ending_here = 0;

    for &num in arr {
        max_ending_here = cmp::max(num, max_ending_here + num);
        max_so_far = cmp::max(max_so_far, max_ending_here);
    }

    max_so_far
}

/// Kadane's Algorithm for circular array
pub fn kadanes_circular(arr: &[i32]) -> i32 {
    if arr.is_empty() {
        return 0;
    }

    // Case 1: Maximum subarray is non-circular
    let max_kadane = kadanes_algorithm(arr);

    // Case 2: Maximum subarray is circular
    // Find minimum subarray sum and subtract from total
    let total_sum: i32 = arr.iter().sum();

    // Invert array signs to find minimum subarray using Kadane's
    let inverted_arr: Vec<i32> = arr.iter().map(|&x| -x).collect();
    let max_inverted = kadanes_algorithm(&inverted_arr);
    let min_subarray = -max_inverted;

    let max_circular = total_sum - min_subarray;

    // If all elements are negative, return max_kadane
    if max_circular == 0 {
        max_kadane
    } else {
        cmp::max(max_kadane, max_circular)
    }
}

/// Handle all negative numbers explicitly
pub fn kadanes_all_negative_handling(arr: &[i32]) -> i32 {
    if arr.is_empty() {
        return 0;
    }

    // If all numbers are negative, return the maximum single element
    if arr.iter().all(|&x| x < 0) {
        return *arr.iter().max().unwrap();
    }

    let mut max_so_far = 0;
    let mut max_ending_here = 0;

    for &num in arr {
        max_ending_here = cmp::max(0, max_ending_here + num);
        max_so_far = cmp::max(max_so_far, max_ending_here);
    }

    max_so_far
}

/// Print array in a formatted way
fn print_array(arr: &[i32]) {
    print!("[");
    for (i, &num) in arr.iter().enumerate() {
        if i > 0 {
            print!(", ");
        }
        print!("{}", num);
    }
    print!("]");
}

/// Print a formatted test case
fn print_test_case(arr: &[i32], description: &str) {
    print!("{}: ", description);
    print_array(arr);
    println!();

    if let Some(result) = kadanes_with_indices(arr) {
        println!("Maximum contiguous sum: {}", result.max_sum);
        print!("Subarray: ");
        print_array(&result.subarray);
        println!(" (indices {} to {})", result.start_index, result.end_index);
        println!("Functional implementation: {}\n", kadanes_functional(arr));
    }
}

fn main() {
    println!("Kadane's Algorithm Examples:\n");

    // Test case 1: Mixed positive and negative numbers
    let arr1 = vec![-2, -3, 4, -1, -2, 1, 5, -3];
    print_test_case(&arr1, "Array 1 (mixed)");

    // Test case 2: All negative numbers
    let arr2 = vec![-2, -3, -1, -5];
    print_test_case(&arr2, "Array 2 (all negative)");

    // Test case 3: All positive numbers
    let arr3 = vec![1, 2, 3, 4, 5];
    print_test_case(&arr3, "Array 3 (all positive)");

    // Test case 4: Single element
    let arr4 = vec![5];
    print_test_case(&arr4, "Array 4 (single element)");

    // Test case 5: Circular array
    let arr5 = vec![5, -3, 5];
    print!("Array 5 (circular test): ");
    print_array(&arr5);
    println!();
    println!("Maximum sum (linear): {}", kadanes_algorithm(&arr5));
    println!("Maximum sum (circular): {}\n", kadanes_circular(&arr5));

    // Edge case: Empty array
    let arr6: Vec<i32> = vec![];
    print!("Empty array: ");
    print_array(&arr6);
    println!(" -> Maximum sum: {}", kadanes_algorithm(&arr6));

    // Test with all negative handling
    println!("\nAll negative handling test:");
    println!("Array 2 result: {}", kadanes_all_negative_handling(&arr2));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_kadanes_basic() {
        let arr = vec![-2, -3, 4, -1, -2, 1, 5, -3];
        assert_eq!(kadanes_algorithm(&arr), 7);
    }

    #[test]
    fn test_kadanes_all_negative() {
        let arr = vec![-2, -3, -1, -5];
        assert_eq!(kadanes_algorithm(&arr), -1);
    }

    #[test]
    fn test_kadanes_all_positive() {
        let arr = vec![1, 2, 3, 4, 5];
        assert_eq!(kadanes_algorithm(&arr), 15);
    }

    #[test]
    fn test_kadanes_empty() {
        let arr: Vec<i32> = vec![];
        assert_eq!(kadanes_algorithm(&arr), 0);
    }

    #[test]
    fn test_kadanes_single_element() {
        let arr = vec![5];
        assert_eq!(kadanes_algorithm(&arr), 5);
    }

    #[test]
    fn test_kadanes_with_indices() {
        let arr = vec![-2, -3, 4, -1, -2, 1, 5, -3];
        let result = kadanes_with_indices(&arr).unwrap();
        assert_eq!(result.max_sum, 7);
        assert_eq!(result.start_index, 2);
        assert_eq!(result.end_index, 6);
        assert_eq!(result.subarray, vec![4, -1, -2, 1, 5]);
    }

    #[test]
    fn test_kadanes_circular() {
        let arr = vec![5, -3, 5];
        assert_eq!(kadanes_circular(&arr), 10); // 5 + 5 (circular)
        assert_eq!(kadanes_algorithm(&arr), 7);  // 5 + (-3) + 5 (linear)
    }
}