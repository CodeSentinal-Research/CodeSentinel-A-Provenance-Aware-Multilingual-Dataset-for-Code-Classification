#include <iostream>
#include <vector>

bool isValidMaxHeap(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) return false;
        if (right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << (isValidMaxHeap(arr) ? "VALID" : "INVALID") << "\n";
    }
    return 0;
}