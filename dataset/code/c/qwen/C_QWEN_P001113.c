#include <stdio.h>
int grid[1000][1000], r, c;
void dfs(int i, int j) {
    if(i<0 || i>=r || j<0 || j>=c || grid[i][j] != 1) return;
    grid[i][j] = 0;
    dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
}
int main() {
    scanf("%d%d", &r, &c);
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &grid[i][j]);
    int count = 0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(grid[i][j] == 1) { dfs(i, j); count++; }
    printf("%d\n", count);
    return 0;
}
