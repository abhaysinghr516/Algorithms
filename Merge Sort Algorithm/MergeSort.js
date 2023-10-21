function merge(arr, beg, mid, end) {
    const l = mid - beg + 1;
    const r = end - mid;
    const LeftArray = new Array(l);
    const RightArray = new Array(r);

    for (let i = 0; i < l; ++i)
        LeftArray[i] = arr[beg + i];
    for (let j = 0; j < r; ++j)
        RightArray[j] = arr[mid + 1 + j];

    let i = 0, j = 0;
    let k = beg;
    
    while (i < l && j < r) {
        if (LeftArray[i] <= RightArray[j]) {
            arr[k] = LeftArray[i];
            i++;
        } else {
            arr[k] = RightArray[j];
            j++;
        }
        k++;
    }
    
    while (i < l) {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }
    
    while (j < r) {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}

function mergeSort(arr, beg, end) {
    if (beg < end) {
        const mid = Math.floor((beg + end) / 2);
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

function main() {
    const arr = [40, 51, 22, 45, 1, 4, 90, 23, 17, 55];
    mergeSort(arr, 0, arr.length - 1);
    console.log("Sorted array:");
    for (let i = 0; i < arr.length; i++) {
        console.log(arr[i] + "");
    }
}

main();