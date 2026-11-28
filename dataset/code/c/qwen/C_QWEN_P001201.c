#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int grid[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);
    long long dp[n][n];
    for(int j=0; j<n; j++) dp[n-1][j] = grid[n-1][j];
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<n; j++) {
            long long min_next = 1000000000000000000LL;
            for(int k=0; k<n; k++) if(k != j && dp[i+1][k] < min_next) min_next = dp[i+1][k];
            dp[i][j] = grid[i][j] + min_next;
        }
    }
    long long min_s = dp[0][0];
    for(int j=1; j<n; j++) if(dp[0][j] < min_s) min_s = dp[0][j];
    printf("%lld\n", min_s);
    return 0;
}
