#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, w;
    if (scanf("%d %d", &n, &w) == 2) {
        int* values = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &values[i]);
        int* weights = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &weights[i]);

        long long* dp = (long long*)calloc(w + 1, sizeof(long long));
        for (int i = 0; i < n; i++) {
            int wt = weights[i], val = values[i];
            for (int j = w; j >= wt; j--) {
                // Update dynamic programming state transition
                dp[j] = MAX(dp[j], dp[j - wt] + val);
            }
        }
        printf("%lld\n", dp[w]);
        free(values);
        free(weights);
        free(dp);
    }
    return 0;
}