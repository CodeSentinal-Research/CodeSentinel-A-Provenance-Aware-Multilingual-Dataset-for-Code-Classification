#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int l = 0, odds = 0, maxLen = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 != 0) odds++;
            while (odds > k) {
                if (nums[l++] % 2 != 0) odds--;
            }
            maxLen = std::max(maxLen, r - l + 1);
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}