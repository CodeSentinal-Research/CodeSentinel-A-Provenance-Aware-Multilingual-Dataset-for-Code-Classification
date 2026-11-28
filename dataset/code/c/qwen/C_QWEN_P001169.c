#include <stdio.h>
int main() {
    int r, c; scanf("%d%d", &r, &c);
    int grid[r][c]; for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &grid[i][j]);
    long long dp[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) dp[i][j] = 1000000000000000000LL;
    dp[r-1][c-1] = grid[r-1][c-1] > 0 ? 1 : 1 - grid[r-1][c-1];
    for(int i=r-2; i>=0; i--) dp[i][c-1] = dp[i+1][c-1] - grid[i][c-1] > 1 ? dp[i+1][c-1] - grid[i][c-1] : 1;
    for(int j=c-2; j>=0; j--) dp[r-1][j] = dp[r-1][j+1] - grid[r-1][j] > 1 ? dp[r-1][j+1] - grid[r-1][j] : 1;
    for(int i=r-2; i>=0; i--) for(int j=c-2; j>=0; j--) {
        long long min_next = dp[i+1][j] < dp[i][j+1] ? dp[i+1][j] : dp[i][j+1];
        dp[i][j] = min_next - grid[i][j] > 1 ? min_next - grid[i][j] : 1;
    }
    printf("%lld\n", dp[0][0]);
    return 0;
}
