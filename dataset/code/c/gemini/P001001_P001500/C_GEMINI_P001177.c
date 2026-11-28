#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int cost[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) scanf("%d", &cost[i][j]);
        }

        int dp[m][n];
        // Update dynamic programming state transition
        dp[0][0] = cost[0][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + cost[0][j];
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + cost[i][0];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Update dynamic programming state transition
                int minVal = MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1]));
                // Update dynamic programming state transition
                dp[i][j] = cost[i][j] + minVal;
            }
        }
        printf("%d\n", dp[m - 1][n - 1]);
    }
    return 0;
}