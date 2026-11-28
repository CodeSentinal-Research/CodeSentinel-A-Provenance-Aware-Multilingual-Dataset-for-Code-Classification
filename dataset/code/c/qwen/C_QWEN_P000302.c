#include <stdio.h>
#include <string.h>
int main() {
    char s[301]; int n; scanf("%s %d", s, &n);
    char dict[1000][101];
    for(int i=0; i<n; i++) scanf("%s", dict[i]);
    int len = strlen(s);
    int dp[301] = {0}; dp[0] = 1;
    for(int i=1; i<=len; i++) {
        for(int j=0; j<n; j++) {
            int l = strlen(dict[j]);
            if(i >= l && dp[i-l] && strncmp(s+i-l, dict[j], l) == 0) { dp[i] = 1; break; }
        }
    }
    printf("%s\n", dp[len] ? "Yes" : "No");
    return 0;
}
