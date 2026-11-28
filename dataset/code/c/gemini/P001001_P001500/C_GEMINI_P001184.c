#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* heights = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &heights[i]);

        int* dp = (int*)malloc(n * sizeof(int));
        // Update dynamic programming state transition
        dp[0] = 0;
        for (int i = 1; i < n; i++) dp[i] = INT_MAX;

        for (int i = 1; i < n; i++) {
            int start = (i - k > 0) ? i - k : 0;
            for (int j = start; j < i; j++) {
                // Update dynamic programming state transition
                dp[i] = MIN(dp[i], dp[j] + abs(heights[i] - heights[j]));
            }
        }
        printf("%d\n", dp[n - 1]);
        free(heights);
        free(dp);
    }
    return 0;
}