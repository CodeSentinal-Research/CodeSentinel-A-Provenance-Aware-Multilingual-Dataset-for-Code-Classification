#include <stdio.h>
int main() {
    int n, amount; scanf("%d%d", &n, &amount);
    int coins[n]; for(int i=0; i<n; i++) scanf("%d", &coins[i]);
    long long dp[amount+1]; for(int i=0; i<=amount; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i=0; i<n; i++) for(int j=coins[i]; j<=amount; j++) dp[j] += dp[j-coins[i]];
    printf("%lld\n", dp[amount]);
    return 0;
}
