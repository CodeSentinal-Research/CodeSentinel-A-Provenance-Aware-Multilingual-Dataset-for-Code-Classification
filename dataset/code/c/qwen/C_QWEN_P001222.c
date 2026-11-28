#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long dp[n+1]; dp[0] = 1;
    for(int i=1; i<=n; i++) dp[i] = dp[i-1] * (4*i - 2) / (i + 1);
    printf("%lld\n", dp[n]);
    return 0;
}
