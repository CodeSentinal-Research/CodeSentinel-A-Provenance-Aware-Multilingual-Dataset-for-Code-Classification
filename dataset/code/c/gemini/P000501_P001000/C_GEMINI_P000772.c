#include <stdio.h>
#define MAX_E 105
#define MAX_F 1005
int dp[MAX_E][MAX_F];
int main() {
    int e, f;
    if (scanf("%d %d", &e, &f) == 2) {
        for (int i = 1; i <= e; i++) { dp[i][1] = 1; dp[i][0] = 0; }
        for (int j = 1; j <= f; j++) dp[1][j] = j;
        for (int i = 2; i <= e; i++) {
            for (int j = 2; j <= f; j++) {
                // Update dynamic programming state transition
                dp[i][j] = 9999999;
                for (int x = 1; x <= j; x++) {
                    // Update dynamic programming state transition
                    int max_v = dp[i - 1][x - 1] > dp[i][j - x] ? dp[i - 1][x - 1] : dp[i][j - x];
                    int res = 1 + max_v;
                    // Update dynamic programming state transition
                    if (res < dp[i][j]) dp[i][j] = res;
                }
            }
        }
        printf("%d\n", dp[e][f]);
    }
    return 0;
}