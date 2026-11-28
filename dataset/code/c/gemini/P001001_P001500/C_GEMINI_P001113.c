#include <stdio.h>

void dfs(char** grid, int r, int c, int m, int n) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
    grid[r][c] = '0';
    dfs(grid, r + 1, c, m, n);
    dfs(grid, r - 1, c, m, n);
    dfs(grid, r, c + 1, m, n);
    dfs(grid, r, c - 1, m, n);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    int m = gridSize, n = gridColSize[0];
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, m, n);
            }
        }
    }
    return count;
}