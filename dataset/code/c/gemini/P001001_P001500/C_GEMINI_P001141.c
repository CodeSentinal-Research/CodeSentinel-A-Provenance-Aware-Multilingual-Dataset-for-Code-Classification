#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        bool* dp = (bool*)calloc(target + 1, sizeof(bool));
        // Update dynamic programming state transition
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            for (int j = target; j >= x; j--) {
                // Update dynamic programming state transition
                dp[j] = dp[j] || dp[j - x];
            }
        }
        printf("%s\n", dp[target] ? "YES" : "NO");
        free(arr);
        free(dp);
    }
    return 0;
}