function bubbleSort(arr) {
  const n = arr.length;
  let swapped;

  do {
    swapped = false;

    for (let i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        // Swap the elements
        const temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;

        swapped = true;
      }
    }
  } while (swapped);

  return arr;
}

const unsortedArray = [97, 45, 5, 37, 10, 75, 19, 57, 85, 65, 24];
const sortedArray = bubbleSort(unsortedArray);
console.log(sortedArray);
