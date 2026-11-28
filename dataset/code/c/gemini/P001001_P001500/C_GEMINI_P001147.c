#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    char s1[1005], s2[1005];
    if (scanf("%s %s", s1, s2) == 2) {
        int m = strlen(s1), n = strlen(s2);
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        int maxLen = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // Update dynamic programming state transition
                    maxLen = MAX(maxLen, dp[i][j]);
                }
            }
        }
        printf("%d\n", maxLen);
    }
    return 0;
}