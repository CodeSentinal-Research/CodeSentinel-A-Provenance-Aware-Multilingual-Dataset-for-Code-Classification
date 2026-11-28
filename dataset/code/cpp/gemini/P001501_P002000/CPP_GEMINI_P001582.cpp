#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int l = 0, zeros = 0, maxLen = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) zeros++;
            while (zeros > k) {
                if (nums[l++] == 0) zeros--;
            }
            maxLen = std::max(maxLen, r - l + 1);
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}