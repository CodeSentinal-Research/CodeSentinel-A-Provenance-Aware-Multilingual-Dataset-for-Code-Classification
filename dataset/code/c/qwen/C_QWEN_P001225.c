#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long dp[n+1]; dp[0]=1; dp[1]=1; dp[2]=2;
    for(int i=3; i<=n; i++) dp[i] = 2*dp[i-1] + dp[i-3];
    printf("%lld\n", dp[n]);
    return 0;
}
