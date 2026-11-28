#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int l = 0, maxLen = 0;
        long long curSum = 0;

        for (int r = 0; r < n; r++) {
            curSum += nums[r];
            while (curSum > k && l <= r) {
                curSum -= nums[l++];
            }
            if (curSum <= k) {
                maxLen = std::max(maxLen, r - l + 1);
            }
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}