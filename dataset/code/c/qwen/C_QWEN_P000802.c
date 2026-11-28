#include <stdio.h>
int main() {
    int n, m, threshold; scanf("%d%d%d", &n, &m, &threshold);
    int grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0]=0;
    for(int j=0; j<=m; j++) prefix[0][j]=0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%d", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    int max_side = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        for(int len=1; len<=n && len<=m; len++) {
            if(i+len>n || j+len>m) break;
            int sum = prefix[i+len][j+len] - prefix[i][j+len] - prefix[i+len][j] + prefix[i][j];
            if(sum <= threshold) max_side = len > max_side ? len : max_side;
            else break;
        }
    }
    printf("%d\n", max_side);
    return 0;
}
