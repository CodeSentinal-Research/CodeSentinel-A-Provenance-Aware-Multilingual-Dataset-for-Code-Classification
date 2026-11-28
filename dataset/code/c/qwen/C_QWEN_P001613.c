#include <stdio.h>

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    long long grid[n][m], prefix[n+1][m+1], res[n][m];
    for(int i=0; i<=n; i++) prefix[i][0] = 0;
    for(int j=0; j<=m; j++) prefix[0][j] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%lld", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        int r1 = i-k < 0 ? 0 : i-k, c1 = j-k < 0 ? 0 : j-k;
        int r2 = i+k >= n ? n-1 : i+k, c2 = j+k >= m ? m-1 : j+k;
        res[i][j] = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
    }
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) printf("%lld%c", res[i][j], j==m-1?'\n':' ');
    return 0;
}
