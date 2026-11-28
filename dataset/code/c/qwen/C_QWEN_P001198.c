#include <stdio.h>
int main() {
    int r, c; scanf("%d%d", &r, &c);
    int grid[r][c]; for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &grid[i][j]);
    int dp[r][c]; long long count = 0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        if(grid[i][j] == 1) {
            dp[i][j] = 1;
            if(i > 0 && j > 0) dp[i][j] += dp[i-1][j-1] < dp[i-1][j] ? (dp[i-1][j-1] < dp[i][j-1] ? dp[i-1][j-1] : dp[i][j-1]) : (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
            count += dp[i][j];
        } else dp[i][j] = 0;
    }
    printf("%lld\n", count);
    return 0;
}
