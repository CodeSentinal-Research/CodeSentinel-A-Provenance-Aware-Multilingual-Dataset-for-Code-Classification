#include <stdio.h>
int main() {
    int r, c; scanf("%d%d", &r, &c);
    int grid[r][c]; for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &grid[i][j]);
    long long dp[r][c];
    for(int i=0; i<r; i++) dp[i][0] = grid[i][0];
    for(int j=1; j<c; j++) for(int i=0; i<r; i++) {
        dp[i][j] = dp[i][j-1] + grid[i][j];
        if(i > 0 && dp[i-1][j-1] + grid[i][j] > dp[i][j]) dp[i][j] = dp[i-1][j-1] + grid[i][j];
        if(i < r-1 && dp[i+1][j-1] + grid[i][j] > dp[i][j]) dp[i][j] = dp[i+1][j-1] + grid[i][j];
    }
    long long max_g = dp[0][c-1];
    for(int i=1; i<r; i++) if(dp[i][c-1] > max_g) max_g = dp[i][c-1];
    printf("%lld\n", max_g);
    return 0;
}
