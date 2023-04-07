function countingSort(arr) {
    let max = arr[0], min = arr[0];

    for (const num of arr) {
        max = Math.max(max, num);
        min = Math.min(min, num);
    }

    const range = max - min + 1;
    const count = new Array(range).fill(0);
    const output = new Array(arr.length).fill(0);

    for (const num of arr)
        count[num - min]++;

    for (let i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (let i = arr.length - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (let i = 0; i < arr.length; i++)
        arr[i] = output[i];
}

const arr = [4, 2, 2, 8, 3, 3, 1];

countingSort(arr);

console.log(arr);
