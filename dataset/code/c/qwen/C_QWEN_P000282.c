#include <stdio.h>
#include <string.h>
int main() {
    char s1[501], s2[501]; scanf("%s %s", s1, s2);
    int l1=strlen(s1), l2=strlen(s2), max_len=0, end=0;
    int dp[501][501];
    for(int i=0; i<=l1; i++) for(int j=0; j<=l2; j++) dp[i][j]=0;
    for(int i=1; i<=l1; i++) for(int j=1; j<=l2; j++) {
        if(s1[i-1]==s2[j-1]) { dp[i][j] = dp[i-1][j-1]+1; if(dp[i][j]>max_len) { max_len=dp[i][j]; end=i; } }
    }
    char res[501]; strncpy(res, s1+end-max_len, max_len); res[max_len]='\0';
    printf("%s\n", res);
    return 0;
}
