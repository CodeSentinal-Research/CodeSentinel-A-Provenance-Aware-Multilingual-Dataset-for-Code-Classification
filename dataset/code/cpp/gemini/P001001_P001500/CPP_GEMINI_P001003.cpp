#include <iostream>
#include <vector>
#include <algorithm>

int findMinInMaxHeap(const std::vector<int>& arr) {
    int n = arr.size();
    int leafStart = n / 2;
    return *std::min_element(arr.begin() + leafStart, arr.end());
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << findMinInMaxHeap(arr) << "\n";
    }
    return 0;
}