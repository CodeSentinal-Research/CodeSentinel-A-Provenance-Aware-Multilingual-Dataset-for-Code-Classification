#include <stdio.h>
#include <string.h>
int main() {
    char s1[5001], s2[5001]; scanf("%s%s", s1, s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    int dp[l1+1][l2+1], max_l = 0;
    for(int i=0; i<=l1; i++) for(int j=0; j<=l2; j++) dp[i][j] = 0;
    for(int i=1; i<=l1; i++) for(int j=1; j<=l2; j++) {
        if(s1[i-1] == s2[j-1]) { dp[i][j] = dp[i-1][j-1] + 1; if(dp[i][j] > max_l) max_l = dp[i][j]; }
    }
    printf("%d\n", max_l);
    return 0;
}
