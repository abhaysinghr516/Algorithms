/**
 * Kadane's Algorithm Implementation in JavaScript
 * 
 * Kadane's Algorithm is used to find the maximum sum of a contiguous subarray 
 * within a one-dimensional array of numbers in O(n) time complexity.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

/**
 * Basic Kadane's Algorithm to find maximum sum of contiguous subarray
 * @param {number[]} arr - Input array
 * @returns {number} Maximum sum of contiguous subarray
 */
function kadanesAlgorithm(arr) {
    if (arr.length === 0) return 0;

    let maxSoFar = Number.NEGATIVE_INFINITY;
    let maxEndingHere = 0;

    for (let i = 0; i < arr.length; i++) {
        maxEndingHere = maxEndingHere + arr[i];

        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }

        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }

    return maxSoFar;
}

/**
 * Kadane's Algorithm that also returns the subarray indices
 * @param {number[]} arr - Input array
 * @returns {Object} Object containing maxSum, startIndex, and endIndex
 */
function kadanesWithIndices(arr) {
    if (arr.length === 0) return { maxSum: 0, startIndex: -1, endIndex: -1 };

    let maxSoFar = Number.NEGATIVE_INFINITY;
    let maxEndingHere = 0;
    let start = 0;
    let end = 0;
    let s = 0; // temporary start index

    for (let i = 0; i < arr.length; i++) {
        maxEndingHere += arr[i];

        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }

        if (maxEndingHere < 0) {
            maxEndingHere = 0;
            s = i + 1;
        }
    }

    return {
        maxSum: maxSoFar,
        startIndex: start,
        endIndex: end,
        subarray: arr.slice(start, end + 1)
    };
}

/**
 * Alternative implementation using reduce
 * @param {number[]} arr - Input array
 * @returns {number} Maximum sum of contiguous subarray
 */
function kadanesReduce(arr) {
    if (arr.length === 0) return 0;

    let maxSoFar = Number.NEGATIVE_INFINITY;

    arr.reduce((maxEndingHere, current) => {
        maxEndingHere = Math.max(current, maxEndingHere + current);
        maxSoFar = Math.max(maxSoFar, maxEndingHere);
        return maxEndingHere;
    }, 0);

    return maxSoFar;
}

/**
 * Kadane's Algorithm for circular array (bonus implementation)
 * @param {number[]} arr - Input array
 * @returns {number} Maximum sum of contiguous subarray in circular array
 */
function kadanesCircular(arr) {
    if (arr.length === 0) return 0;

    // Case 1: Maximum subarray is non-circular
    const maxKadane = kadanesAlgorithm(arr);

    // Case 2: Maximum subarray is circular
    // Find minimum subarray sum and subtract from total
    const totalSum = arr.reduce((sum, num) => sum + num, 0);

    // Invert array signs to find minimum subarray using Kadane's
    const invertedArr = arr.map(num => -num);
    const maxInverted = kadanesAlgorithm(invertedArr);
    const minSubarray = -maxInverted;

    const maxCircular = totalSum - minSubarray;

    // If all elements are negative, return maxKadane
    return maxCircular === 0 ? maxKadane : Math.max(maxKadane, maxCircular);
}

// Example usage and testing
function main() {
    console.log("Kadane's Algorithm Examples:\n");

    // Test case 1: Mixed positive and negative numbers
    const arr1 = [-2, -3, 4, -1, -2, 1, 5, -3];
    console.log("Array 1:", arr1);
    console.log("Maximum contiguous sum:", kadanesAlgorithm(arr1));
    console.log("With indices:", kadanesWithIndices(arr1));
    console.log();

    // Test case 2: All negative numbers
    const arr2 = [-2, -3, -1, -5];
    console.log("Array 2:", arr2);
    console.log("Maximum contiguous sum:", kadanesAlgorithm(arr2));
    console.log();

    // Test case 3: All positive numbers
    const arr3 = [1, 2, 3, 4, 5];
    console.log("Array 3:", arr3);
    console.log("Maximum contiguous sum:", kadanesAlgorithm(arr3));
    console.log();

    // Test case 4: Circular array
    const arr4 = [5, -3, 5];
    console.log("Array 4 (circular):", arr4);
    console.log("Maximum contiguous sum (linear):", kadanesAlgorithm(arr4));
    console.log("Maximum contiguous sum (circular):", kadanesCircular(arr4));
    console.log();

    // Performance comparison
    console.log("Reduce implementation result:", kadanesReduce(arr1));
}

// Run the example
main();

// Export for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        kadanesAlgorithm,
        kadanesWithIndices,
        kadanesReduce,
        kadanesCircular
    };
}