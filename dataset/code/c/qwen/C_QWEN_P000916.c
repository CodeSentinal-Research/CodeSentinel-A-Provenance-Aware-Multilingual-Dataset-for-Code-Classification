#include <stdio.h>
#define MOD 1000000007
int main() {
    int n; scanf("%d", &n);
    long long dp[n+1]; dp[0] = 1; dp[1] = 0;
    for(int i=2; i<=n; i++) dp[i] = (i - 1) * (dp[i-1] + dp[i-2]) % MOD;
    printf("%lld\n", dp[n]);
    return 0;
}
