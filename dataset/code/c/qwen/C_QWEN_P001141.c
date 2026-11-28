#include <stdio.h>
int main() {
    int n, s; scanf("%d%d", &n, &s);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int dp[s+1]; for(int i=0; i<=s; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i=0; i<n; i++) for(int j=s; j>=a[i]; j--) dp[j] = dp[j] || dp[j-a[i]];
    printf("%s\n", dp[s] ? "YES" : "NO");
    return 0;
}
