#include <stdio.h>
#include <string.h>
int main() {
    char s[5001]; scanf("%s", s);
    int n = strlen(s);
    int dp[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = 0;
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int i=n-1; i>=0; i--) for(int j=i+1; j<n; j++) {
        if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
        else dp[i][j] = dp[i+1][j] > dp[i][j-1] ? dp[i+1][j] : dp[i][j-1];
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}
