#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int h[n]; for(int i=0; i<n; i++) scanf("%d", &h[i]);
    long long dp[n]; dp[0] = 0;
    for(int i=1; i<n; i++) {
        dp[i] = 1000000000000000000LL;
        for(int j=1; j<=k && i-j>=0; j++) { long long cost = dp[i-j] + abs(h[i] - h[i-j]); if(cost < dp[i]) dp[i] = cost; }
    }
    printf("%lld\n", dp[n-1]);
    return 0;
}
