#include <stdio.h>
int main() {
    int n, amount; scanf("%d%d", &n, &amount);
    int coins[n]; for(int i=0; i<n; i++) scanf("%d", &coins[i]);
    int dp[amount+1]; for(int i=0; i<=amount; i++) dp[i] = 1000000000;
    dp[0] = 0;
    for(int i=0; i<n; i++) for(int j=coins[i]; j<=amount; j++) if(dp[j-coins[i]] + 1 < dp[j]) dp[j] = dp[j-coins[i]] + 1;
    printf("%d\n", dp[amount] == 1000000000 ? -1 : dp[amount]);
    return 0;
}
