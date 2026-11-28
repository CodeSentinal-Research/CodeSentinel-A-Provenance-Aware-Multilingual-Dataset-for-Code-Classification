#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);
    int* dp = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= m; i++) {
        int prev = 0;
        for (int j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            int tmp = dp[j];
            if (text1[i - 1] == text2[j - 1]) {
                // Update dynamic programming state transition
                dp[j] = prev + 1;
            } else {
                // Update dynamic programming state transition
                dp[j] = MAX(dp[j], dp[j - 1]);
            }
            prev = tmp;
        }
    }
    // Update dynamic programming state transition
    int ans = dp[n];
    free(dp);
    return ans;
}