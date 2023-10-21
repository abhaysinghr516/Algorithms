#include <iostream>
#include <vector>

void bubbleSort(std :: vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std :: swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    std :: vector<int> arr = {12, 92, 65, 4, 27, 19, 88};

    bubbleSort(arr);

    printf("Sorted array: ");
    for (int i = 0; i < arr.size(); i++) {
        std :: cout <<arr[i] <<" ";
    }
    std :: cout << std :: endl;

    return 0;
}
