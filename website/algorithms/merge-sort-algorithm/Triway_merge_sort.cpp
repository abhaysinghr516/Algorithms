#include <iostream>
#include <vector>

/**
 * Merge three subarrays: [left, mid1), [mid1, mid2), [mid2, right)
 *
 * @param arr The array to be merged
 * @param left The left index of the subarray
 * @param mid1 The middle index of the first subarray
 * @param mid2 The middle index of the second subarray
 * @param right The right index of the subarray
 */
void merge(std::vector<int> &arr, int left, int mid1, int mid2, int right) {
    int n1 = mid1 - left;
    int n2 = mid2 - mid1;
    int n3 = right - mid2;

    std::vector<int> leftArr(n1);
    std::vector<int> midArr(n2);
    std::vector<int> rightArr(n3);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        midArr[i] = arr[mid1 + i];
    for (int i = 0; i < n3; i++)
        rightArr[i] = arr[mid2 + i];

    int i = 0, j = 0, k = 0, index = left;

    // Merge the three arrays back into arr
    while (i < n1 && j < n2 && k < n3) {
        if (leftArr[i] <= midArr[j] && leftArr[i] <= rightArr[k]) {
            arr[index++] = leftArr[i++];
        } else if (midArr[j] <= leftArr[i] && midArr[j] <= rightArr[k]) {
            arr[index++] = midArr[j++];
        } else {
            arr[index++] = rightArr[k++];
        }
    }

    // Copy any remaining elements if any
    while (i < n1)
        arr[index++] = leftArr[i++];
    while (j < n2)
        arr[index++] = midArr[j++];
    while (k < n3)
        arr[index++] = rightArr[k++];
}

/**
 * Perform three-way merge sort on an array
 *
 * @param arr The array to be sorted
 * @param left The left index of the subarray
 * @param right The right index of the subarray
 */
void mergeSort(std::vector<int> &arr, int left, int right) {
    if (right - left > 1) {
        int n = right - left;
        int mid1 = left + n / 3;
        int mid2 = left + 2 * n / 3;

        mergeSort(arr, left, mid1);
        mergeSort(arr, mid1, mid2);
        mergeSort(arr, mid2, right);

        merge(arr, left, mid1, mid2, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 10, 21, 9, 8, 1, 11, 13, 21, 10, 19, 6, 7, 10};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    mergeSort(arr, 0, n);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
