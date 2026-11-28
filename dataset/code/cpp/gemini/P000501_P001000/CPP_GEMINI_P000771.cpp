#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> keys(n), freq(n);
        for (int i = 0; i < n; i++) std::cin >> keys[i];
        for (int i = 0; i < n; i++) std::cin >> freq[i];
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));
        std::vector<std::vector<long long>> sum_f(n, std::vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            long long s = 0;
            for (int j = i; j < n; j++) { s += freq[j]; sum_f[i][j] = s; }
            // Update dynamic programming state transition
            dp[i][i] = freq[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                long long min_c = LLONG_MAX;
                for (int r = i; r <= j; r++) {
                    // Update dynamic programming state transition
                    long long c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0);
                    min_c = std::min(min_c, c);
                }
                // Update dynamic programming state transition
                dp[i][j] = min_c + sum_f[i][j];
            }
        }
        std::cout << dp[0][n - 1] << std::endl;
    }
    return 0;
}