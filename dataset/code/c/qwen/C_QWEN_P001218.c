#include <stdio.h>
#include <string.h>
int main() {
    char s[5001]; scanf("%s", s);
    int m; scanf("%d", &m);
    char dict[m][101]; for(int i=0; i<m; i++) scanf("%s", dict[i]);
    int n = strlen(s);
    int dp[n+1]; for(int i=0; i<=n; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<m; j++) {
            int len = strlen(dict[j]);
            if(i >= len && dp[i-len]) {
                if(strncmp(s+i-len, dict[j], len) == 0) { dp[i] = 1; break; }
            }
        }
    }
    printf("%s\n", dp[n] ? "YES" : "NO");
    return 0;
}
