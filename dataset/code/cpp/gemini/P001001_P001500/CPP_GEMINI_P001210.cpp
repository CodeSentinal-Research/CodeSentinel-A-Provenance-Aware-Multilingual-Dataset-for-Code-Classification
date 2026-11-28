#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Update dynamic programming state transition
                long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
                // Update dynamic programming state transition
                long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                // Update dynamic programming state transition
                long long z = (i <= j - 2) ? dp[i][j - 2] : 0;
                // Update dynamic programming state transition
                dp[i][j] = std::max(arr[i] + std::min(x, y), arr[j] + std::min(y, z));
            }
        }
        std::cout << dp[0][n - 1] << "\n";
    }
    return 0;
}