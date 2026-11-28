#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* prices = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &prices[i]);

        long long* dp = (long long*)calloc(n + 1, sizeof(long long));
        for (int i = 1; i <= n; i++) {
            long long maxVal = 0;
            for (int j = 0; j < i; j++) {
                // Update dynamic programming state transition
                maxVal = MAX(maxVal, prices[j] + dp[i - j - 1]);
            }
            // Update dynamic programming state transition
            dp[i] = maxVal;
        }
        printf("%lld\n", dp[n]);
        free(prices);
        free(dp);
    }
    return 0;
}