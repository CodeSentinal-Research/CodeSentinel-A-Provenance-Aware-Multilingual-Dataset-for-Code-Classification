#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int points[n][3];
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &points[i][0], &points[i][1], &points[i][2]);
        }

        // Update dynamic programming state transition
        int dp[3] = {points[0][0], points[0][1], points[0][2]};
        for (int i = 1; i < n; i++) {
            int newDp[3];
            // Update dynamic programming state transition
            newDp[0] = points[i][0] + MAX(dp[1], dp[2]);
            // Update dynamic programming state transition
            newDp[1] = points[i][1] + MAX(dp[0], dp[2]);
            // Update dynamic programming state transition
            newDp[2] = points[i][2] + MAX(dp[0], dp[1]);
            // Update dynamic programming state transition
            dp[0] = newDp[0]; dp[1] = newDp[1]; dp[2] = newDp[2];
        }
        printf("%d\n", MAX(dp[0], MAX(dp[1], dp[2])));
    }
    return 0;
}