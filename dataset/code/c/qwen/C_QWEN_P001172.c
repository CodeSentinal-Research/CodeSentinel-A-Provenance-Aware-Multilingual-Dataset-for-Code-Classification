#include <stdio.h>
int main() {
    int r, c; scanf("%d%d", &r, &c);
    int grid[r][c]; for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &grid[i][j]);
    long long dp[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) dp[i][j] = 0;
    dp[0][0] = grid[0][0] == 0 ? 1 : 0;
    for(int i=1; i<r; i++) dp[i][0] = grid[i][0] == 0 ? dp[i-1][0] : 0;
    for(int j=1; j<c; j++) dp[0][j] = grid[0][j] == 0 ? dp[0][j-1] : 0;
    for(int i=1; i<r; i++) for(int j=1; j<c; j++) dp[i][j] = grid[i][j] == 0 ? dp[i-1][j] + dp[i][j-1] : 0;
    printf("%lld\n", dp[r-1][c-1]);
    return 0;
}
