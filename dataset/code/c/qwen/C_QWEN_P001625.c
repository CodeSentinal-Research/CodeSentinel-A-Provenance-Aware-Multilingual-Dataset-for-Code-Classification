#include <stdio.h>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    long long grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0] = 0;
    for(int j=0; j<=m; j++) prefix[0][j] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%lld", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) printf("%lld%c", prefix[i][j], j==m?'\n':' ');
    return 0;
}
