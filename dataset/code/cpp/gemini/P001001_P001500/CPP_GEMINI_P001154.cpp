#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));
        for (int len = 2; len < n; len++) {
            for (int i = 1; i <= n - len; i++) {
                int j = i + len - 1;
                // Update dynamic programming state transition
                dp[i][j] = LLONG_MAX;
                for (int k = i; k < j; k++) {
                    // Update dynamic programming state transition
                    long long q = dp[i][k] + dp[k + 1][j] + (long long)arr[i - 1] * arr[k] * arr[j];
                    // Update dynamic programming state transition
                    if (q < dp[i][j]) dp[i][j] = q;
                }
            }
        }
        std::cout << dp[1][n - 1] << "\n";
    }
    return 0;
}