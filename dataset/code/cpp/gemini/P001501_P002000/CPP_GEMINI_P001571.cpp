#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int maxDiff = 0;
        for (int i = 0; i <= n - k; i++) {
            maxDiff = std::max(maxDiff, std::abs(nums[i + k - 1] - nums[i]));
        }
        std::cout << maxDiff << "\n";
    }
    return 0;
}