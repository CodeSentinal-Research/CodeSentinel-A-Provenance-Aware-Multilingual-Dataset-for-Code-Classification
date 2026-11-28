#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long dp[n + 1];
        // Update dynamic programming state transition
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // Update dynamic programming state transition
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                // Update dynamic programming state transition
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}