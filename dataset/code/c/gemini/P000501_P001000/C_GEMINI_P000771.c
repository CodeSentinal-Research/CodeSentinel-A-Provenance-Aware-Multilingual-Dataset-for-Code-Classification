#include <stdio.h>
#define MAX_N 105
int keys[MAX_N], freq[MAX_N];
long long dp[MAX_N][MAX_N], sum_f[MAX_N][MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &keys[i]);
        for (int i = 0; i < n; i++) scanf("%d", &freq[i]);
        for (int i = 0; i < n; i++) {
            long long s = 0;
            for (int j = i; j < n; j++) { s += freq[j]; sum_f[i][j] = s; }
            // Update dynamic programming state transition
            dp[i][i] = freq[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                long long min_c = -1;
                for (int r = i; r <= j; r++) {
                    // Update dynamic programming state transition
                    long long c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0);
                    if (min_c == -1 || c < min_c) min_c = c;
                }
                // Update dynamic programming state transition
                dp[i][j] = min_c + sum_f[i][j];
            }
        }
        printf("%lld\n", dp[0][n - 1]);
    }
    return 0;
}