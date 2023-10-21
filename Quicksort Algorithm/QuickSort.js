function partition(arr, lowIndex, highIndex) {
    const pivot = arr[highIndex];
    let i = lowIndex - 1;
    for (let j = lowIndex; j < highIndex; j++) {
        if (arr[j] <= pivot) {
            i++;
            [arr[i], arr[j]] = [arr[j], arr[i]]; // Swap elements at i and j
        }
    }
    [arr[i + 1], arr[highIndex]] = [arr[highIndex], arr[i + 1]]; // Swap pivot with element at i+1
    return i + 1;
}

function quickSort(arr, lowIndex, highIndex) {
    if (lowIndex < highIndex) {
        const pi = partition(arr, lowIndex, highIndex);
        quickSort(arr, lowIndex, pi - 1);
        quickSort(arr, pi + 1, highIndex);
    }
}

function printArray(arr) {
    const n = arr.length;
    for (let i = 0; i < n; i++) {
        process.stdout.write(arr[i] + " ");
    }
    console.log();
}

function main() {
    const arr = [101, 37, 68, 29, 11, 5];
    const n = arr.length;
    quickSort(arr, 0, n - 1);
    console.log("Sorted array:");
    printArray(arr);
}

main();