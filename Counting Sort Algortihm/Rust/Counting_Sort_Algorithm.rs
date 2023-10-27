fn counting_sort(arr: &mut [i32]) {
    let mut max = arr[0];
    let mut min = arr[0];

    // Find the maximum and minimum values in the array
    for &num in arr.iter() {
        max = max.max(num);
        min = min.min(num);
    }

    let range = (max - min + 1) as usize;
    let mut count = vec![0; range];
    let mut output = vec![0; arr.len()];

    // Count the occurrences of each element
    for &num in arr.iter() {
        count[(num - min) as usize] += 1;
    }

    // Calculate the cumulative counts
    for i in 1..range {
        count[i] += count[i - 1];
    }

    // Build the sorted output
    for i in (0..arr.len()).rev() {
        let num = arr[i];
        let index = (num - min) as usize;
        output[count[index] as usize - 1] = num;
        count[index] -= 1;
    }

    // Copy the sorted elements back to the original array
    arr.copy_from_slice(&output);
}

fn main() {
    let mut arr = vec![4, 2, 2, 8, 3, 3, 1];
    counting_sort(&mut arr);
    println!("{:?}", arr);
}
