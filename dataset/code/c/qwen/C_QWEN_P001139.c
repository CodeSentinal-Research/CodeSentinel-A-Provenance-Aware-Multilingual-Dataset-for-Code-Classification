#include <stdio.h>
int main() {
    int n, w; scanf("%d%d", &n, &w);
    int wt[n], val[n]; for(int i=0; i<n; i++) scanf("%d%d", &wt[i], &val[i]);
    long long dp[w+1]; for(int i=0; i<=w; i++) dp[i] = 0;
    for(int i=0; i<n; i++) for(int j=w; j>=wt[i]; j--) if(dp[j-wt[i]] + val[i] > dp[j]) dp[j] = dp[j-wt[i]] + val[i];
    printf("%lld\n", dp[w]);
    return 0;
}
