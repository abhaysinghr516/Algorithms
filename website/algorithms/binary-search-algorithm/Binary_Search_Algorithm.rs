fn binary_search(arr: &[i32], x: i32) -> i32 {
    let mut left = 0;
    let mut right = arr.len() as i32 - 1;

    while left <= right {
        let mid = left + (right - left) / 2;

        if arr[mid as usize] == x {
            return mid;
        } else if arr[mid as usize] < x {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    -1
}

fn main() {
    let arr = vec![2, 3, 4, 10, 40];
    let x = 10;

    let result = binary_search(&arr, x);
    if result != -1 {
        println!("Element found at index {}", result);
    } else {
        println!("Element not found in the array");
    }
}
