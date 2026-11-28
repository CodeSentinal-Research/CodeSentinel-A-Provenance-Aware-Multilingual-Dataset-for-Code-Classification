#include <stdio.h>
int main() {
    int r, c, k; scanf("%d%d%d", &r, &c, &k);
    int sr, sc; scanf("%d%d", &sr, &sc);
    long long dp[k+1][r][c];
    for(int i=0; i<=k; i++) for(int x=0; x<r; x++) for(int y=0; y<c; y++) dp[i][x][y] = 0;
    dp[0][sr][sc] = 1;
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    for(int i=0; i<k; i++) {
        for(int x=0; x<r; x++) for(int y=0; y<c; y++) {
            if(dp[i][x][y] > 0) {
                for(int d=0; d<4; d++) {
                    int nx=x+dx[d], ny=y+dy[d];
                    if(nx<0 || nx>=r || ny<0 || ny>=c) dp[i+1][0][0] += dp[i][x][y]; // simplified
                    else dp[i+1][nx][ny] += dp[i][x][y];
                }
            }
        }
    }
    long long paths = 0;
    for(int x=0; x<r; x++) for(int y=0; y<c; y++) if(x<0||x>=r||y<0||y>=c) paths += dp[k][x][y];
    printf("%lld\n", paths);
    return 0;
}
