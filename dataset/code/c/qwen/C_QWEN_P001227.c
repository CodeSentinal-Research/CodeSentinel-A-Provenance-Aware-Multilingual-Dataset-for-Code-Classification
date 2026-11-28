#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long dp[n+1]; dp[1]=0; dp[2]=1;
    for(int i=3; i<=n; i++) dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    printf("%lld\n", dp[n]);
    return 0;
}
