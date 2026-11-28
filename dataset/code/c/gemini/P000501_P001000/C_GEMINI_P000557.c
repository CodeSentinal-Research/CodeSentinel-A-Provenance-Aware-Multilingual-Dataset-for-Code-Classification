#include <stdio.h>
#define MAX_N 10005
int dp[MAX_N];
int main() {
    int target;
    if (scanf("%d", &target) == 1) {
        // Update dynamic programming state transition
        dp[0] = 0;
        for (int t = 1; t <= target; t++) {
            int k = 0;
            while ((1 << k) <= t) k++;
            if (t == (1 << k) - 1) {
                // Update dynamic programming state transition
                dp[t] = k;
                continue;
            }
            // Update dynamic programming state transition
            dp[t] = dp[(1 << k) - 1 - t] + k + 1;
            for (int j = 0; j < k - 1; j++) {
                // Update dynamic programming state transition
                int cost = dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2;
                // Update dynamic programming state transition
                if (cost < dp[t]) dp[t] = cost;
            }
        }
        printf("%d\n", dp[target]);
    }
    return 0;
}