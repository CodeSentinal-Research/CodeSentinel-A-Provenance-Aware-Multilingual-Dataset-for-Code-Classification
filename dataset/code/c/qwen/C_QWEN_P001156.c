#include <stdio.h>
int main() {
    int e, f; scanf("%d%d", &e, &f);
    int dp[e+1][f+1];
    for(int i=0; i<=e; i++) for(int j=0; j<=f; j++) dp[i][j] = 0;
    for(int i=1; i<=e; i++) for(int j=1; j<=f; j++) {
        dp[i][j] = 1000000000;
        for(int x=1; x<=j; x++) { int cost = 1 + (dp[i-1][x-1] > dp[i][j-x] ? dp[i-1][x-1] : dp[i][j-x]); if(cost < dp[i][j]) dp[i][j] = cost; }
    }
    printf("%d\n", dp[e][f]);
    return 0;
}
