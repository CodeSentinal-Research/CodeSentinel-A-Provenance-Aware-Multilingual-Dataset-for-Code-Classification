#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int act[n][3]; for(int i=0; i<n; i++) scanf("%d%d%d", &act[i][0], &act[i][1], &act[i][2]);
    long long dp[n][3];
    dp[0][0] = act[0][0]; dp[0][1] = act[0][1]; dp[0][2] = act[0][2];
    for(int i=1; i<n; i++) {
        dp[i][0] = act[i][0] + (dp[i-1][1] > dp[i-1][2] ? dp[i-1][1] : dp[i-1][2]);
        dp[i][1] = act[i][1] + (dp[i-1][0] > dp[i-1][2] ? dp[i-1][0] : dp[i-1][2]);
        dp[i][2] = act[i][2] + (dp[i-1][0] > dp[i-1][1] ? dp[i-1][0] : dp[i-1][1]);
    }
    long long max_m = dp[n-1][0];
    if(dp[n-1][1] > max_m) max_m = dp[n-1][1];
    if(dp[n-1][2] > max_m) max_m = dp[n-1][2];
    printf("%lld\n", max_m);
    return 0;
}
