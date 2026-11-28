#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

int main() {
    int k, n;
    if (std::cin >> k >> n) {
        std::vector<long long> coeffs(k);
        for (int i = 0; i < k; i++) std::cin >> coeffs[i];
        std::vector<long long> dp(std::max(k, n + 1));
        for (int i = 0; i < k; i++) std::cin >> dp[i];
        for (int i = k; i <= n; i++) {
            long long val = 0;
            for (int j = 0; j < k; j++) {
                // Update dynamic programming state transition
                val = (val + coeffs[j] * dp[i - 1 - j]) % MOD;
            }
            // Update dynamic programming state transition
            dp[i] = val;
        }
        std::cout << (dp[n] % MOD + MOD) % MOD << "\n";
    }
    return 0;
}