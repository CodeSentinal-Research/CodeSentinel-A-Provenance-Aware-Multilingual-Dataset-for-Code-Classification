#include <iostream>
#include <vector>
#include <algorithm>

int countFrequency(const std::vector<int>& arr, int target) {
    return std::count(arr.begin(), arr.end(), target);
}

int main() {
    int n, target;
    if (std::cin >> n >> target && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << countFrequency(arr, target) << "\n";
    }
    return 0;
}