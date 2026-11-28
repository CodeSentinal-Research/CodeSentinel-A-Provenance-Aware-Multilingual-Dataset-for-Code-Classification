#include <string.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int editDistance(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    // Update dynamic programming state transition
    int dp[105][105] = {0};

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Update dynamic programming state transition
                dp[i][j] = 1 + MIN3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[m][n];
}