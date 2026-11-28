#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int n, x;
    if (std::cin >> n >> x) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        int l = 0, minLen = INT_MAX;
        long long curSum = 0;

        for (int r = 0; r < n; r++) {
            curSum += nums[r];
            while (curSum > x) {
                minLen = std::min(minLen, r - l + 1);
                curSum -= nums[l++];
            }
        }
        std::cout << (minLen != INT_MAX ? minLen : 0) << "\n";
    }
    return 0;
}