#include <stdio.h>
#include <string.h>

double diceSumProb(int n, int target) {
    if (target < n || target > 6 * n) return 0.0;
    double dp[600 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 6; i++) dp[i] = 1.0 / 6.0;

    for (int dice = 2; dice <= n; dice++) {
        double nextDp[600 + 1];
        memset(nextDp, 0, sizeof(nextDp));
        for (int s = dice; s <= 6 * dice; s++) {
            for (int face = 1; face <= 6; face++) {
                if (s - face >= dice - 1) {
                    // Update dynamic programming state transition
                    nextDp[s] += dp[s - face] / 6.0;
                }
            }
        }
        memcpy(dp, nextDp, sizeof(dp));
    }
    return dp[target];
}

int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        printf("%.6f\n", diceSumProb(n, target));
    }
    return 0;
}