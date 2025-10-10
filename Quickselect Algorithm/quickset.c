#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for(int j = left; j < right; j++) {
        if(arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

int quickselect(int arr[], int left, int right, int k) {
    if(left == right) return arr[left];
    
    int pivotIndex = partition(arr, left, right);
    
    if(k == pivotIndex)
        return arr[k];
    else if(k < pivotIndex)
        return quickselect(arr, left, pivotIndex - 1, k);
    else
        return quickselect(arr, pivotIndex + 1, right, k);
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3; // 3rd smallest element
    int result = quickselect(arr, 0, n - 1, k - 1);
    printf("The %d-th smallest element is %d\n", k, result);
    return 0;
}
