#include <stdio.h>

int find_majority_element(int arr[], int n) {
    int candidate = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
        }
        count += (arr[i] == candidate) ? 1 : -1;
    }
    
    return candidate;
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = find_majority_element(arr, n);
    printf("Majority element is: %d\n", result);
    
    return 0;
}
