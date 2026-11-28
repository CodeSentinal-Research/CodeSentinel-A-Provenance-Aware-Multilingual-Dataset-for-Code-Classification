#include <stdio.h>
int main() {
    int d, f, s; scanf("%d%d%d", &d, &f, &s);
    long long dp[d+1][s+1];
    for(int i=0; i<=d; i++) for(int j=0; j<=s; j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i=1; i<=d; i++) {
        for(int j=1; j<=s; j++) {
            for(int k=1; k<=f && k<=j; k++) dp[i][j] += dp[i-1][j-k];
        }
    }
    printf("%lld\n", dp[d][s]);
    return 0;
}
