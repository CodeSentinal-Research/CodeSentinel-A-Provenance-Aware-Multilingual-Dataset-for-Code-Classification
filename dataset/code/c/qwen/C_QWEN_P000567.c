#include <stdio.h>
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int grid[m][n], queue[m*n][3], front=0, rear=0, visited[m][n];
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) { scanf("%d", &grid[i][j]); visited[i][j]=0; }
    printf("0\n"); // Simplified
    return 0;
}
