#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; scanf("%s", s);
    int n = strlen(s);
    long long dp[n+1]; for(int i=0; i<=n; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        if(s[i-1] != '0') dp[i] = dp[i-1];
        if(i >= 2) { int val = (s[i-2]-'0')*10 + (s[i-1]-'0'); if(val >= 10 && val <= 26) dp[i] += dp[i-2]; }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
