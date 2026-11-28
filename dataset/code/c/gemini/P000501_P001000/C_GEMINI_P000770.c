#include <stdio.h>
#define MAX_N 105
int dims[MAX_N];
long long dp[MAX_N][MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &dims[i]);
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                // Update dynamic programming state transition
                dp[i][j] = -1;
                for (int k = i; k < j; k++) {
                    // Update dynamic programming state transition
                    long long cost = dp[i][k] + dp[k + 1][j] + (long long)dims[i - 1] * dims[k] * dims[j];
                    // Update dynamic programming state transition
                    if (dp[i][j] == -1 || cost < dp[i][j]) dp[i][j] = cost;
                }
            }
        }
        printf("%lld\n", dp[1][n - 1]);
    }
    return 0;
}