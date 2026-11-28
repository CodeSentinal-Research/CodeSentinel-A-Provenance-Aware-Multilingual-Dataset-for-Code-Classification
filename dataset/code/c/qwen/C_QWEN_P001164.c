#include <stdio.h>
#include <string.h>
int main() {
    char a[2001], b[2001]; scanf("%s%s", a, b);
    int l1 = strlen(a), l2 = strlen(b);
    long long dp[l1+1][l2+1];
    for(int i=0; i<=l1; i++) for(int j=0; j<=l2; j++) dp[i][j] = 0;
    for(int i=1; i<=l1; i++) dp[i][0] = dp[i-1][0] + a[i-1];
    for(int j=1; j<=l2; j++) dp[0][j] = dp[0][j-1] + b[j-1];
    for(int i=1; i<=l1; i++) for(int j=1; j<=l2; j++) {
        if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = a[i-1] + dp[i-1][j] < b[j-1] + dp[i][j-1] ? a[i-1] + dp[i-1][j] : b[j-1] + dp[i][j-1];
    }
    printf("%lld\n", dp[l1][l2]);
    return 0;
}
