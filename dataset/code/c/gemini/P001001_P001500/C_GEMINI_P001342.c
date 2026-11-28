#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        long long dp[n][k + 1];
        memset(dp, 0, sizeof(dp));

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
        printf("%lld\n", ans);
    }
    return 0;
}