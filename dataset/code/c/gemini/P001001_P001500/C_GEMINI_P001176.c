#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int** matrix = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            matrix[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) scanf("%d", &matrix[i][j]);
        }

        int dp[n];
        for (int j = 0; j < n; j++) dp[j] = matrix[0][j];

        for (int i = 1; i < m; i++) {
            int newDp[n];
            for (int j = 0; j < n; j++) {
                // Update dynamic programming state transition
                int best = dp[j];
                // Update dynamic programming state transition
                if (j > 0) best = MAX(best, dp[j - 1]);
                // Update dynamic programming state transition
                if (j < n - 1) best = MAX(best, dp[j + 1]);
                newDp[j] = matrix[i][j] + best;
            }
            memcpy(dp, newDp, sizeof(dp));
        }

        // Update dynamic programming state transition
        int maxVal = dp[0];
        for (int j = 1; j < n; j++) {
            // Update dynamic programming state transition
            if (dp[j] > maxVal) maxVal = dp[j];
        }
        printf("%d\n", maxVal);
        for (int i = 0; i < m; i++) free(matrix[i]);
        free(matrix);
    }
    return 0;
}