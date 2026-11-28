#include <string.h>
#include <stdlib.h>

int numDistinct(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    unsigned long long* dp = (unsigned long long*)calloc(n + 1, sizeof(unsigned long long));
    // Update dynamic programming state transition
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                // Update dynamic programming state transition
                dp[j] += dp[j - 1];
            }
        }
    }
    // Update dynamic programming state transition
    int ans = (int)dp[n];
    free(dp);
    return ans;
}