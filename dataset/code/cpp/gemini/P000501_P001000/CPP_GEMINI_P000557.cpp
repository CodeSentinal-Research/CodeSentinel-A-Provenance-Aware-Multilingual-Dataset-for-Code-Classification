#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int target;
    if (std::cin >> target) {
        std::vector<int> dp(target + 1, 0);
        for (int t = 1; t <= target; t++) {
            int k = 0;
            while ((1 << k) <= t) k++;
            if (t == (1 << k) - 1) {
                // Update dynamic programming state transition
                dp[t] = k;
                continue;
            }
            // Update dynamic programming state transition
            dp[t] = dp[(1 << k) - 1 - t] + k + 1;
            for (int j = 0; j < k - 1; j++) {
                // Update dynamic programming state transition
                dp[t] = std::min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2);
            }
        }
        std::cout << dp[target] << std::endl;
    }
    return 0;
}