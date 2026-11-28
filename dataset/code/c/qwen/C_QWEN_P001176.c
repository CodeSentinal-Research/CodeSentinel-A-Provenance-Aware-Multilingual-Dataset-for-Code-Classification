#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int grid[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);
    long long dp[n][n];
    for(int j=0; j<n; j++) dp[0][j] = grid[0][j];
    for(int i=1; i<n; i++) for(int j=0; j<n; j++) {
        dp[i][j] = dp[i-1][j] + grid[i][j];
        if(j > 0 && dp[i-1][j-1] + grid[i][j] > dp[i][j]) dp[i][j] = dp[i-1][j-1] + grid[i][j];
        if(j < n-1 && dp[i-1][j+1] + grid[i][j] > dp[i][j]) dp[i][j] = dp[i-1][j+1] + grid[i][j];
    }
    long long max_s = dp[n-1][0];
    for(int j=1; j<n; j++) if(dp[n-1][j] > max_s) max_s = dp[n-1][j];
    printf("%lld\n", max_s);
    return 0;
}
