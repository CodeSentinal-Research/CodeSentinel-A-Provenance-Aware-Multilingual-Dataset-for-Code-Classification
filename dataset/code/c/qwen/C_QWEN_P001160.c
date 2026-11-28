#include <stdio.h>
#include <string.h>
int main() {
    char s[2001], t[2001]; scanf("%s%s", s, t);
    int l1 = strlen(s), l2 = strlen(t);
    long long dp[l1+1][l2+1];
    for(int i=0; i<=l1; i++) for(int j=0; j<=l2; j++) dp[i][j] = 0;
    for(int i=0; i<=l1; i++) dp[i][0] = 1;
    for(int i=1; i<=l1; i++) for(int j=1; j<=l2; j++) {
        dp[i][j] = dp[i-1][j];
        if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
    }
    printf("%lld\n", dp[l1][l2]);
    return 0;
}
