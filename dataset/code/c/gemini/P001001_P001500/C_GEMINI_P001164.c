#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int* dp = (int*)calloc(n + 1, sizeof(int));
    for (int j = 1; j <= n; j++) {
        // Update dynamic programming state transition
        dp[j] = dp[j - 1] + (int)s2[j - 1];
    }

    for (int i = 1; i <= m; i++) {
        // Update dynamic programming state transition
        int prev = dp[0];
        // Update dynamic programming state transition
        dp[0] += (int)s1[i - 1];
        for (int j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            int tmp = dp[j];
            if (s1[i - 1] == s2[j - 1]) {
                // Update dynamic programming state transition
                dp[j] = prev;
            } else {
                // Update dynamic programming state transition
                dp[j] = MIN(dp[j] + (int)s1[i - 1], dp[j - 1] + (int)s2[j - 1]);
            }
            prev = tmp;
        }
    }
    // Update dynamic programming state transition
    int ans = dp[n];
    free(dp);
    return ans;
}