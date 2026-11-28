#include <iostream>
#include <vector>

int xorAll(const std::vector<int>& arr) {
    int ans = 0;
    for (int x : arr) ans ^= x;
    return ans;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::cout << xorAll(arr) << "\n";
    }
    return 0;
}