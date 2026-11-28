#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        long long dp[n][n];
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Update dynamic programming state transition
                long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
                // Update dynamic programming state transition
                long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                // Update dynamic programming state transition
                long long z = (i <= j - 2) ? dp[i][j - 2] : 0;
                // Update dynamic programming state transition
                dp[i][j] = MAX(arr[i] + MIN(x, y), arr[j] + MIN(y, z));
            }
        }
        printf("%lld\n", dp[0][n - 1]);
        free(arr);
    }
    return 0;
}