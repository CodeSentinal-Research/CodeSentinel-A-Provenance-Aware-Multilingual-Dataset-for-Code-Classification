#include <iostream>
#include <vector>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        long long MOD = 1e9 + 7;
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(k + 1, 0));

        for (int i = 0; i < n; i++) dp[i][1] = 1;

        for (int len = 2; len <= k; len++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[j] < arr[i]) {
                        // Update dynamic programming state transition
                        dp[i][len] = (dp[i][len] + dp[j][len - 1]) % MOD;
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) ans = (ans + dp[i][k]) % MOD;
        std::cout << ans << "\n";
    }
    return 0;
}