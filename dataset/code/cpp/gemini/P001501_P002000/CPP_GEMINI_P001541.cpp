#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        long long curSum = 0;
        for (int i = 0; i < k; i++) curSum += nums[i];
        long long maxSum = curSum;

        for (int i = k; i < n; i++) {
            curSum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, curSum);
        }
        std::cout << maxSum << "\n";
    }
    return 0;
}