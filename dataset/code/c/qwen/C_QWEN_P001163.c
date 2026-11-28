#include <stdio.h>
#include <string.h>
int main() {
    char a[2001], b[2001], c[4002]; scanf("%s%s%s", a, b, c);
    int l1 = strlen(a), l2 = strlen(b), l3 = strlen(c);
    if(l1 + l2 != l3) { printf("NO\n"); return 0; }
    int dp[l1+1][l2+1];
    for(int i=0; i<=l1; i++) for(int j=0; j<=l2; j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i=0; i<=l1; i++) for(int j=0; j<=l2; j++) {
        if(i > 0 && a[i-1] == c[i+j-1]) dp[i][j] = dp[i][j] || dp[i-1][j];
        if(j > 0 && b[j-1] == c[i+j-1]) dp[i][j] = dp[i][j] || dp[i][j-1];
    }
    printf("%s\n", dp[l1][l2] ? "YES" : "NO");
    return 0;
}
