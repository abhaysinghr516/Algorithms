/*Binary search is an efficient algorithm for finding an item from a sorted list of items.
It works by repeatedly dividing in half the portion of the list that could contain the item,
until you've narrowed down the possible locations to just one

Binary search runs in logarithmic time in the worst case, making 
O(log n) comparisons, where n is the number of elements in the array.
Binary search is faster than linear search except for small arrays.
However, the array must be sorted first to be able to apply binary search. 
*/


fn binary_search(arr: &[i32], target: i32) -> Option<usize> {
    let mut low = 0; // Initialize the low index to the beginning of the array
    let mut high = arr.len() - 1; // Initialize the high index to the end of the array

    while low <= high {
        let mid = low + (high - low) / 2; // Calculate the middle index

        if arr[mid] == target {
            return Some(mid); // Target found, return the index
        } else if arr[mid] < target {
            low = mid + 1; // Adjust the low index to search the right half
        } else {
            high = mid - 1; // Adjust the high index to search the left half
        }
    }

    None // Target not found in the array
}

fn main() {
    let arr = [1, 3, 5, 7, 9, 11, 13, 15];
    let target = 7;

    if let Some(index) = binary_search(&arr, target) {
        println!("Target {} found at index {}.", target, index);
    } else {
        println!("Target {} not found in the array.", target);
    }
}
