#include <stdio.h>
int main() {
    int r, c; scanf("%d%d", &r, &c);
    long long dp[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) dp[i][j] = 0;
    for(int i=0; i<r; i++) dp[i][0] = 1;
    for(int j=0; j<c; j++) dp[0][j] = 1;
    for(int i=1; i<r; i++) for(int j=1; j<c; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
    printf("%lld\n", dp[r-1][c-1]);
    return 0;
}
