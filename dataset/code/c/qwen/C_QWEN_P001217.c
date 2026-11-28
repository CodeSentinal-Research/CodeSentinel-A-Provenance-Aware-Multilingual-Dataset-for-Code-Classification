#include <stdio.h>
#include <string.h>
int isPal(char *s, int i, int j) { while(i<j) if(s[i++]!=s[j--]) return 0; return 1; }
int main() {
    char s[5001]; scanf("%s", s);
    int n = strlen(s);
    int dp[n+1]; for(int i=0; i<=n; i++) dp[i] = i-1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if(isPal(s, j, i-1)) dp[i] = dp[i] < dp[j]+1 ? dp[i] : dp[j]+1;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
