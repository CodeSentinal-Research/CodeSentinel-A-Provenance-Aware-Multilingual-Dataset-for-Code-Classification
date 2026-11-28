#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDistance(char* word1, char* word2) {
    int m = strlen(word1), n = strlen(word2);
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    for (int j = 0; j <= n; j++) dp[j] = j;

    for (int i = 1; i <= m; i++) {
        // Update dynamic programming state transition
        int prev = dp[0];
        // Update dynamic programming state transition
        dp[0] = i;
        for (int j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            int tmp = dp[j];
            if (word1[i - 1] == word2[j - 1]) {
                // Update dynamic programming state transition
                dp[j] = prev;
            } else {
                // Update dynamic programming state transition
                dp[j] = 1 + MIN(prev, MIN(dp[j], dp[j - 1]));
            }
            prev = tmp;
        }
    }
    // Update dynamic programming state transition
    int ans = dp[n];
    free(dp);
    return ans;
}