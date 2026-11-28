#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long dp[n+1]; dp[0] = 1;
    for(int i=1; i<=n; i++) {
        dp[i] = 0;
        for(int j=0; j<i; j++) dp[i] += dp[j] * dp[i-1-j];
    }
    printf("%lld\n", dp[n]);
    return 0;
}
