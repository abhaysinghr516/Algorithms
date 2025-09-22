function findMajorityElement(arr) {
    let candidate = 0;
    let count = 0;

    for (const num of arr) {
        if (count === 0) {
            candidate = num;
        }
        count += (num === candidate) ? 1 : -1;
    }

    return candidate;
}

const arr = [2, 2, 1, 1, 2, 2];

const result = findMajorityElement(arr);
console.log("Majority element is:", result);
