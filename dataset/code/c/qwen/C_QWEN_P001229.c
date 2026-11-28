#include <stdio.h>
int main() {
    int n, k, r, c; scanf("%d%d%d%d", &n, &k, &r, &c);
    double dp[n+1][n][n];
    for(int i=0; i<=n; i++) for(int x=0; x<n; x++) for(int y=0; y<n; y++) dp[i][x][y] = 0;
    dp[0][r][c] = 1.0;
    int dx[]={-2,-2,-1,-1,1,1,2,2}, dy[]={-1,1,-2,2,-2,2,-1,1};
    for(int i=0; i<k; i++) {
        for(int x=0; x<n; x++) for(int y=0; y<n; y++) {
            if(dp[i][x][y] > 0) {
                for(int d=0; d<8; d++) {
                    int nx=x+dx[d], ny=y+dy[d];
                    if(nx>=0 && nx<n && ny>=0 && ny<n) dp[i+1][nx][ny] += dp[i][x][y] / 8.0;
                }
            }
        }
    }
    double prob = 0;
    for(int x=0; x<n; x++) for(int y=0; y<n; y++) prob += dp[k][x][y];
    printf("%.6f\n", prob);
    return 0;
}
