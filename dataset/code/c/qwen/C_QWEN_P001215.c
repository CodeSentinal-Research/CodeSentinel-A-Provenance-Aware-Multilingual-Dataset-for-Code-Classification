#include <stdio.h>
#include <string.h>
int dp[201][201][201];
int solve(int *a, int i, int j, int k) {
    if(i > j) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int res = (k+1)*(k+1) + solve(a, i+1, j, 0);
    for(int m=i+1; m<=j; m++) if(a[m] == a[i]) res = res > (solve(a, i+1, m-1, 0) + solve(a, m, j, k+1)) ? res : (solve(a, i+1, m-1, 0) + solve(a, m, j, k+1));
    return dp[i][j][k] = res;
}
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(a, 0, n-1, 0));
    return 0;
}
