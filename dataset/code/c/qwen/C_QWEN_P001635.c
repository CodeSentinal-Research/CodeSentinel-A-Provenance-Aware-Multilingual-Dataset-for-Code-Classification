#include <stdio.h>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0] = 0;
    for(int j=0; j<=m; j++) prefix[0][j] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%d", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    int count = 0;
    for(int r1=0; r1<n; r1++) for(int r2=r1; r2<n; r2++) {
        for(int c1=0; c1<m; c1++) for(int c2=c1; c2<m; c2++) {
            long long sum = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
            long long area = (r2-r1+1) * (c2-c1+1);
            if(sum * 2 == area) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
