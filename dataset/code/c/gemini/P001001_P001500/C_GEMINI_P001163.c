#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int m = strlen(s1), n = strlen(s2), l = strlen(s3);
    if (m + n != l) return false;

    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    // Update dynamic programming state transition
    dp[0] = true;
    for (int j = 1; j <= n; j++) {
        // Update dynamic programming state transition
        dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    }

    for (int i = 1; i <= m; i++) {
        // Update dynamic programming state transition
        dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    // Update dynamic programming state transition
    bool ans = dp[n];
    free(dp);
    return ans;
}