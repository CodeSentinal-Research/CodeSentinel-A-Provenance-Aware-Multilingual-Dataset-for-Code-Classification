#include <stdio.h>
int grid[64][64];
long long dp[64][64];
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) scanf("%d", &grid[i][j]);
        }
        if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0) { printf("0\n"); return 0; }
        // Update dynamic programming state transition
        dp[0][0] = 1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 0) continue;
                // Update dynamic programming state transition
                if (r > 0) dp[r][c] += dp[r - 1][c];
                // Update dynamic programming state transition
                if (c > 0) dp[r][c] += dp[r][c - 1];
            }
        }
        printf("%lld\n", dp[n - 1][m - 1]);
    }
    return 0;
}