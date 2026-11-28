#include <stdio.h>

int n;
long long dp[55][6];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 5; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    long long sum = 0;
    for (int i = 1; i <= 5; i++) sum += dp[n][i];
    printf("%lld\n", sum);
    return 0;
}
