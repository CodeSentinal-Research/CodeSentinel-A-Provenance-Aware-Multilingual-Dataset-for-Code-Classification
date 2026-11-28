#include <stdio.h>
#include <string.h>
int dp[501][501];
int solve(char *s, int i, int j) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j) return 1;
    int res = 1 + solve(s, i+1, j);
    for(int k=i+1; k<=j; k++) if(s[k] == s[i]) res = res < (solve(s, i+1, k-1) + solve(s, k, j)) ? res : (solve(s, i+1, k-1) + solve(s, k, j));
    return dp[i][j] = res;
}
int main() {
    char s[501]; scanf("%s", s);
    int n = strlen(s);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(s, 0, n-1));
    return 0;
}
