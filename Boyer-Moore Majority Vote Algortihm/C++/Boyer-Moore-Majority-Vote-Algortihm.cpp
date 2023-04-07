#include <iostream>
#include <vector>

int find_majority_element(const std::vector<int>& arr) {
    int candidate = 0;
    int count = 0;

    for (int num : arr) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    std::vector<int> arr = {2, 2, 1, 1, 2, 2};

    int result = find_majority_element(arr);
    std::cout << "Majority element is: " << result << std::endl;

    return 0;
}
