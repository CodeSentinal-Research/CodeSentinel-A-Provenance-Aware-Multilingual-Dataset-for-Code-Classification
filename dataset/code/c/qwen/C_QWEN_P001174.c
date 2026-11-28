#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int tri[n][n]; for(int i=0; i<n; i++) for(int j=0; j<=i; j++) scanf("%d", &tri[i][j]);
    long long dp[n];
    for(int j=0; j<n; j++) dp[j] = tri[n-1][j];
    for(int i=n-2; i>=0; i--) for(int j=0; j<=i; j++) dp[j] = tri[i][j] + (dp[j] < dp[j+1] ? dp[j] : dp[j+1]);
    printf("%lld\n", dp[0]);
    return 0;
}
