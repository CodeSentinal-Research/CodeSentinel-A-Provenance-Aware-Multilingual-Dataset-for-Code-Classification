#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> prices(n);
        for (int i = 0; i < n; i++) std::cin >> prices[i];

        std::vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            long long maxVal = 0;
            for (int j = 0; j < i; j++) {
                // Update dynamic programming state transition
                maxVal = std::max(maxVal, (long long)prices[j] + dp[i - j - 1]);
            }
            // Update dynamic programming state transition
            dp[i] = maxVal;
        }
        std::cout << dp[n] << "\n";
    }
    return 0;
}