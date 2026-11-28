#include <stdio.h>
#include <stdlib.h>
int main() {
    int n; scanf("%d", &n);
    int keys[n], p[n], q[n+1];
    for(int i=0; i<n; i++) scanf("%d", &keys[i]);
    for(int i=0; i<n; i++) scanf("%d", &p[i]);
    for(int i=0; i<=n; i++) scanf("%d", &q[i]);
    long long dp[n+1][n+1], w[n+1][n+1];
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) { dp[i][j]=0; w[i][j]=0; }
    for(int i=0; i<=n; i++) { dp[i][i] = q[i]; w[i][i] = q[i]; }
    for(int L=1; L<=n; L++) {
        for(int i=0; i<=n-L; i++) {
            int j = i+L;
            w[i][j] = w[i][j-1] + p[j-1] + q[j];
            dp[i][j] = 1000000000000000000LL;
            for(int k=i+1; k<=j; k++) {
                long long cost = dp[i][k-1] + dp[k][j] + w[i][j];
                if(cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    printf("%lld\n", dp[0][n]);
    return 0;
}
