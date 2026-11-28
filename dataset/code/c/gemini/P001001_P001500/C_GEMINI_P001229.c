#include <string.h>

double knightProbability(int n, int k, int row, int column) {
    double dp[n][n];
    memset(dp, 0, sizeof(dp));
    // Update dynamic programming state transition
    dp[row][column] = 1.0;

    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int step = 0; step < k; step++) {
        double newDp[n][n];
        memset(newDp, 0, sizeof(newDp));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (dp[r][c] > 0) {
                    for (int d = 0; d < 8; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            // Update dynamic programming state transition
                            newDp[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
        }
        memcpy(dp, newDp, sizeof(dp));
    }

    double sum = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) sum += dp[r][c];
    }
    return sum;
}