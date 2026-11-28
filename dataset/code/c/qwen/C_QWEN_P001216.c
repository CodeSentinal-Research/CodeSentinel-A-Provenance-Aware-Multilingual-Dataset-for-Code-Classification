#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int dp[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = 0;
    for(int len=2; len<=n; len++) {
        for(int i=0; i<=n-len; i++) {
            int j = i+len-1;
            dp[i][j] = 1000000000;
            for(int k=i; k<j; k++) {
                int max_l = a[i], max_r = a[k+1];
                for(int x=i; x<=k; x++) if(a[x]>max_l) max_l=a[x];
                for(int x=k+1; x<=j; x++) if(a[x]>max_r) max_r=a[x];
                int cost = dp[i][k] + dp[k+1][j] + max_l * max_r;
                if(cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}
