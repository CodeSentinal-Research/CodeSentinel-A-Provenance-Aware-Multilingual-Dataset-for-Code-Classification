#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int dims[n+1]; for(int i=0; i<=n; i++) scanf("%d", &dims[i]);
    long long dp[n+1][n+1];
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j] = 0;
    for(int len=2; len<=n; len++) for(int i=1; i<=n-len+1; i++) {
        int j = i+len-1; dp[i][j] = 1000000000000000000LL;
        for(int k=i; k<j; k++) { long long cost = dp[i][k] + dp[k+1][j] + (long long)dims[i-1]*dims[k]*dims[j]; if(cost < dp[i][j]) dp[i][j] = cost; }
    }
    printf("%lld\n", dp[1][n]);
    return 0;
}
