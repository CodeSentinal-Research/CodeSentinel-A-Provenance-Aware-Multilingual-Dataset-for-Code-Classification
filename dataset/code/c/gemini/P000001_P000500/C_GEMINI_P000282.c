#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestCommonSubstr(char* S1, char* S2, int n, int m) {
    // Update dynamic programming state transition
    int dp[1005][1005] = {0};
    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // Update dynamic programming state transition
                res = MAX(res, dp[i][j]);
            }
        }
    }
    return res;
}