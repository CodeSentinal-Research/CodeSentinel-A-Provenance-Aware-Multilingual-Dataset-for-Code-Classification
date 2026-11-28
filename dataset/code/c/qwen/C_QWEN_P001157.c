#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int price[n+1]; for(int i=1; i<=n; i++) scanf("%d", &price[i]);
    long long dp[n+1]; for(int i=0; i<=n; i++) dp[i] = 0;
    for(int i=1; i<=n; i++) for(int j=1; j<=i; j++) if(dp[j] + price[i-j] > dp[i]) dp[i] = dp[j] + price[i-j];
    printf("%lld\n", dp[n]);
    return 0;
}
