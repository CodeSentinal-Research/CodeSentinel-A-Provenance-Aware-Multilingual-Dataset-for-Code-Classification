#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int mine[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) scanf("%d", &mine[i][j]);
        }

        int dp[m][n];
        for (int i = 0; i < m; i++) dp[i][0] = mine[i][0];

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                // Update dynamic programming state transition
                int best = dp[i][j - 1];
                // Update dynamic programming state transition
                if (i > 0) best = MAX(best, dp[i - 1][j - 1]);
                // Update dynamic programming state transition
                if (i < m - 1) best = MAX(best, dp[i + 1][j - 1]);
                // Update dynamic programming state transition
                dp[i][j] = mine[i][j] + best;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) ans = MAX(ans, dp[i][n - 1]);
        printf("%d\n", ans);
    }
    return 0;
}