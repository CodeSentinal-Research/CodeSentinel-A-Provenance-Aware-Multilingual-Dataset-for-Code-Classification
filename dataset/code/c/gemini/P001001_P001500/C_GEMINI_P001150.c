#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    int* dp = (int*)calloc(n, sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        int* newDp = (int*)calloc(n, sizeof(int));
        newDp[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                // Update dynamic programming state transition
                newDp[j] = dp[j - 1] + 2;
            } else {
                // Update dynamic programming state transition
                newDp[j] = MAX(dp[j], newDp[j - 1]);
            }
        }
        free(dp);
        dp = newDp;
    }
    // Update dynamic programming state transition
    int ans = dp[n - 1];
    free(dp);
    return ans;
}