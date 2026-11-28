#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        long long dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) dp[i][j] = 0;
        }

        for (int len = 2; len < n; len++) {
            for (int i = 1; i <= n - len; i++) {
                int j = i + len - 1;
                // Update dynamic programming state transition
                dp[i][j] = LLONG_MAX;
                for (int k = i; k < j; k++) {
                    // Update dynamic programming state transition
                    long long q = dp[i][k] + dp[k + 1][j] + (long long)arr[i - 1] * arr[k] * arr[j];
                    // Update dynamic programming state transition
                    if (q < dp[i][j]) dp[i][j] = q;
                }
            }
        }
        printf("%lld\n", dp[1][n - 1]);
        free(arr);
    }
    return 0;
}