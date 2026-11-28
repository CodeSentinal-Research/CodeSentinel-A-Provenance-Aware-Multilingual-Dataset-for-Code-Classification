#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int cost[n]; for(int i=0; i<n; i++) scanf("%d", &cost[i]);
    long long dp[n]; dp[0] = cost[0]; dp[1] = cost[1];
    for(int i=2; i<n; i++) dp[i] = cost[i] + (dp[i-1] < dp[i-2] ? dp[i-1] : dp[i-2]);
    printf("%lld\n", dp[n-1] < dp[n-2] ? dp[n-1] : dp[n-2]);
    return 0;
}
