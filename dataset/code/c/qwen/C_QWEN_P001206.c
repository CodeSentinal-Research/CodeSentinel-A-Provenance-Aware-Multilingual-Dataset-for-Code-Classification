#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int dp[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = 0;
    for(int i=0; i<n; i++) dp[i][i] = a[i];
    for(int len=2; len<=n; len++) {
        for(int i=0; i<=n-len; i++) {
            int j = i+len-1;
            dp[i][j] = (a[i] - dp[i+1][j]) > (a[j] - dp[i][j-1]) ? (a[i] - dp[i+1][j]) : (a[j] - dp[i][j-1]);
        }
    }
    printf("%s\n", dp[0][n-1] >= 0 ? "YES" : "NO");
    return 0;
}
