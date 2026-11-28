#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int m = dungeonSize, n = dungeonColSize[0];
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) dp[i][j] = 1000000000;
    }
    // Update dynamic programming state transition
    dp[m][n - 1] = dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // Update dynamic programming state transition
            int minReq = MIN(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            // Update dynamic programming state transition
            dp[i][j] = MAX(1, minReq);
        }
    }
    return dp[0][0];
}