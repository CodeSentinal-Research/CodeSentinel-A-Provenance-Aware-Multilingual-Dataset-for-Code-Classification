#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    long long dp[n+2][n+2];
    for(int i=0; i<=n+1; i++) for(int j=0; j<=n+1; j++) dp[i][j] = 0;
    for(int len=1; len<=n; len++) for(int i=0; i<=n-len; i++) {
        int j = i+len-1; dp[i][j] = 0;
        for(int k=i; k<=j; k++) { long long val = (i>0 ? a[i-1] : 1) * a[k] * (j<n-1 ? a[j+1] : 1); long long cost = dp[i][k-1] + dp[k+1][j] + val; if(cost > dp[i][j]) dp[i][j] = cost; }
    }
    printf("%lld\n", dp[0][n-1]);
    return 0;
}
