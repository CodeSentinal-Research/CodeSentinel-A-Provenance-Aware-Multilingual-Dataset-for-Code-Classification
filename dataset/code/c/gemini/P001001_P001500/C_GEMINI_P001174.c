#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int n = triangleSize;
    int* dp = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) dp[j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // Update dynamic programming state transition
            dp[j] = triangle[i][j] + MIN(dp[j], dp[j + 1]);
        }
    }
    // Update dynamic programming state transition
    int ans = dp[0];
    free(dp);
    return ans;
}