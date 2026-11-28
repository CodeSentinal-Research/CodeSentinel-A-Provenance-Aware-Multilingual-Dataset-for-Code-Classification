#include <iostream>
#include <vector>

// Sorts the input array into ordered sequence.
bool isSortedAscending(const std::vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << (isSortedAscending(arr) ? "YES" : "NO") << "\n";
    }
    return 0;
}