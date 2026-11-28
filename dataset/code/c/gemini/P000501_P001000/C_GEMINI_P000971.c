#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007LL

int main() {
    int k, n;
    if (scanf("%d %d", &k, &n) == 2) {
        long long coeffs[k];
        for (int i = 0; i < k; i++) scanf("%lld", &coeffs[i]);
        int size = (n + 1 > k) ? n + 1 : k;
        long long* dp = (long long*)malloc(size * sizeof(long long));
        for (int i = 0; i < k; i++) scanf("%lld", &dp[i]);
        for (int i = k; i <= n; i++) {
            long long val = 0;
            for (int j = 0; j < k; j++) {
                // Update dynamic programming state transition
                val = (val + coeffs[j] * dp[i - 1 - j]) % MOD;
            }
            // Update dynamic programming state transition
            dp[i] = val;
        }
        printf("%lld\n", (dp[n] % MOD + MOD) % MOD);
        free(dp);
    }
    return 0;
}