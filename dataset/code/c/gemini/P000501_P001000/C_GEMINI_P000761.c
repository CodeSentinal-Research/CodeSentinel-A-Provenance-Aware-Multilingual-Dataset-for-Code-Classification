#include <stdio.h>
#include <string.h>
char s[1005], t[1005];
unsigned long long dp[1005][1005];
int main() {
    if (scanf("%1004s %1004s", s, t) == 2) {
        int n = strlen(s), m = strlen(t);
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j];
                // Update dynamic programming state transition
                if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        printf("%llu\n", dp[n][m]);
    }
    return 0;
}