#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> heights(n);
        for (int i = 0; i < n; i++) std::cin >> heights[i];

        std::vector<int> dp(n, INT_MAX);
        // Update dynamic programming state transition
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = std::max(0, i - k); j < i; j++) {
                // Update dynamic programming state transition
                dp[i] = std::min(dp[i], dp[j] + std::abs(heights[i] - heights[j]));
            }
        }
        std::cout << dp[n - 1] << "\n";
    }
    return 0;
}