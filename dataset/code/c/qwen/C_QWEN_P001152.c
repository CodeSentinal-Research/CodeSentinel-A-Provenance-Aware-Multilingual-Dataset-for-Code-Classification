#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int n = strlen(s);
    long long dp[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = 0;
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int len=2; len<=n; len++) for(int i=0; i<=n-len; i++) {
        int j = i+len-1;
        if(s[i] == s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
        else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    }
    printf("%lld\n", dp[0][n-1]);
    return 0;
}
