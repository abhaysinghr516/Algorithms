fn boyer_moore_majority_vote(nums: &[i32]) -> Option<i32> {
    let mut candidate = 0;
    let mut count = 0;

    for &num in nums {
        if count == 0 {
            candidate = num;
            count = 1;
        } else if candidate == num {
            count += 1;
        } else {
            count -= 1;
        }
    }

    // After the first pass, 'candidate' may be the majority element, but we need to verify it.
    count = 0;
    for &num in nums {
        if candidate == num {
            count += 1;
        }
    }

    if count > nums.len() / 2 {
        Some(candidate)
    } else {
        None
    }
}

fn main() {
    let nums = vec![3, 3, 4, 2, 4, 4, 2, 4, 4];
    if let Some(majority_element) = boyer_moore_majority_vote(&nums) {
        println!("The majority element is: {}", majority_element);
    } else {
        println!("No majority element found.");
    }
}