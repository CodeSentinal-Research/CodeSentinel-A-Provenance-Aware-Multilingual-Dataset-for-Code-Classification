#include <stdio.h>
#include <string.h>
int main() {
    char s[2001], p[2001]; scanf("%s%s", s, p);
    int l1 = strlen(s), l2 = strlen(p);
    int dp[l1+1][l2+1];
    for(int i=0; i<=l1; i++) for(int j=0; j<=l2; j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int j=1; j<=l2; j++) if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
    for(int i=1; i<=l1; i++) for(int j=1; j<=l2; j++) {
        if(p[j-1] == '?' || p[j-1] == s[i-1]) dp[i][j] = dp[i-1][j-1];
        else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
    }
    printf("%s\n", dp[l1][l2] ? "YES" : "NO");
    return 0;
}
