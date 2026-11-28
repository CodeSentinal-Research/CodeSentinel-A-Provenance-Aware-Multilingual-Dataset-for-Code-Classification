#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL

int main() {
    int n, k, target;
    if (scanf("%d %d %d", &n, &k, &target) == 3) {
        long long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        // Update dynamic programming state transition
        dp[0] = 1;

        for (int step = 0; step < n; step++) {
            long long newDp[target + 1];
            memset(newDp, 0, sizeof(newDp));
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k; face++) {
                    if (j >= face) {
                        // Update dynamic programming state transition
                        newDp[j] = (newDp[j] + dp[j - face]) % MOD;
                    }
                }
            }
            memcpy(dp, newDp, sizeof(dp));
        }
        printf("%lld\n", dp[target]);
    }
    return 0;
}