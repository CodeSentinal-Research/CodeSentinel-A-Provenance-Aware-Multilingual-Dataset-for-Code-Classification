#include <stdio.h>
#include <stdlib.h>
int main() {
    int n; scanf("%d", &n);
    int h[n]; for(int i=0; i<n; i++) scanf("%d", &h[i]);
    long long dp[n]; dp[0] = 0;
    for(int i=1; i<n; i++) {
        dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        if(i >= 2) { long long cost = dp[i-2] + abs(h[i] - h[i-2]); if(cost < dp[i]) dp[i] = cost; }
    }
    printf("%lld\n", dp[n-1]);
    return 0;
}
