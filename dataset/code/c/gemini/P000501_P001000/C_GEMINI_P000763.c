#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char s[1005], p[1005];
bool dp[1005][1005];
int main() {
    if (scanf("%1004s %1004s", s, p) == 2) {
        int n = strlen(s), m = strlen(p);
        // Update dynamic programming state transition
        dp[0][0] = true;
        for (int j = 2; j <= m; j += 2) {
            // Update dynamic programming state transition
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                        // Update dynamic programming state transition
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        printf("%s\n", dp[n][m] ? "true" : "false");
    }
    return 0;
}