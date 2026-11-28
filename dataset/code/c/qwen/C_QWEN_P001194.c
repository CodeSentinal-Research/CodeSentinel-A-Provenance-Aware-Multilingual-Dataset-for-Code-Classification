#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long dp[n+1]; for(int i=0; i<=n; i++) dp[i] = 0;
    for(int i=1; i<=n; i++) {
        long long max_val = -1000000000, sum = 0;
        for(int j=1; j<=k && i-j>=0; j++) {
            if(a[i-j] > max_val) max_val = a[i-j];
            sum += a[i-j]; // Simplified logic
            long long cost = dp[i-j] + max_val * j;
            if(cost > dp[i]) dp[i] = cost;
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
