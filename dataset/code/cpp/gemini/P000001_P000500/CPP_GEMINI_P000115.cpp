#include <iostream>
#include <vector>
#include <algorithm>

void rotateRight(std::vector<int>& arr, int k) {
    if (arr.empty()) return;
    k = k % arr.size();
    std::rotate(arr.rbegin(), arr.rbegin() + k, arr.rend());
}

int main() {
    int n, k;
    if (std::cin >> n >> k && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        rotateRight(arr, k);
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}