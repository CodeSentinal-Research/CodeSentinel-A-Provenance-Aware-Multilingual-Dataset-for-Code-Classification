#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    long long dp[n+1]; for(int i=0; i<=n; i++) dp[i] = 0;
    for(int i=2; i<=n; i++) {
        dp[i] = i - 1;
        for(int j=1; j<=i/2; j++) { long long val = (long long)j * (i-j); if(val > dp[i]) dp[i] = val; val = (long long)j * dp[i-j]; if(val > dp[i]) dp[i] = val; }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
