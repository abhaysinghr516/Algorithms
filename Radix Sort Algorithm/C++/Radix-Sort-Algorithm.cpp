#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);
    
    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Calculate cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array in reverse order to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy output array to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int maxVal = getMax(arr);
    
    // Do counting sort for every digit position
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 2, 802, 24, 66};
    
    cout << "Original array: ";
    printArray(arr);
    
    radixSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    // Test with another example
    vector<int> arr2 = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
    
    cout << "\nOriginal array 2: ";
    printArray(arr2);
    
    radixSort(arr2);
    
    cout << "Sorted array 2: ";
    printArray(arr2);
    
    return 0;
}