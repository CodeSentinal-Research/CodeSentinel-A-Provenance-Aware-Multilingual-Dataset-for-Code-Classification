#include <stdio.h>
#include <string.h>
int main() {
    int n, m, target; scanf("%d%d%d", &n, &m, &target);
    int grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0]=0;
    for(int j=0; j<=m; j++) prefix[0][j]=0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%d", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    int count = 0;
    for(int r1=0; r1<n; r1++) for(int r2=r1; r2<n; r2++) {
        int map[2000001]; memset(map, 0, sizeof(map));
        map[1000000] = 1; int sum = 0;
        for(int c=0; c<m; c++) {
            sum = prefix[r2+1][c+1] - prefix[r1][c+1];
            int rem = sum - target + 1000000;
            if(rem >= 0 && rem <= 2000000) count += map[rem];
            map[sum + 1000000]++;
        }
    }
    printf("%d\n", count);
    return 0;
}
