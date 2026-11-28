#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    if(k >= n/2) { long long p = 0; for(int i=1; i<n; i++) if(a[i] > a[i-1]) p += a[i] - a[i-1]; printf("%lld\n", p); return 0; }
    long long dp[k+1][n];
    for(int i=0; i<=k; i++) for(int j=0; j<n; j++) dp[i][j] = 0;
    for(int i=1; i<=k; i++) {
        long long max_diff = -a[0];
        for(int j=1; j<n; j++) {
            dp[i][j] = dp[i][j-1] > max_diff + a[j] ? dp[i][j-1] : max_diff + a[j];
            if(dp[i-1][j] - a[j] > max_diff) max_diff = dp[i-1][j] - a[j];
        }
    }
    printf("%lld\n", dp[k][n-1]);
    return 0;
}
