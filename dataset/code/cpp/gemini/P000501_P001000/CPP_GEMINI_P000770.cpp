#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> dims(n);
        for (int i = 0; i < n; i++) std::cin >> dims[i];
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                // Update dynamic programming state transition
                dp[i][j] = LLONG_MAX;
                for (int k = i; k < j; k++) {
                    // Update dynamic programming state transition
                    long long cost = dp[i][k] + dp[k + 1][j] + (long long)dims[i - 1] * dims[k] * dims[j];
                    // Update dynamic programming state transition
                    dp[i][j] = std::min(dp[i][j], cost);
                }
            }
        }
        std::cout << dp[1][n - 1] << std::endl;
    }
    return 0;
}