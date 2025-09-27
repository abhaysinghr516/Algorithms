#include <iostream>
#include <vector>

void counting_sort(std::vector<int>& arr) {
    int max = arr[0], min = arr[0];

    for (int num : arr) {
        max = std::max(max, num);
        min = std::min(min, num);
    }

    int range = max - min + 1;
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());

    for (int num : arr)
        count[num - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    arr = output;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    counting_sort(arr);

    for (int num : arr)
        std::cout << num << " ";

    return 0;
}
