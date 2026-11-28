#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k && n > 0 && k <= n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++) {
            std::cout << arr[i] << (i == k - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}