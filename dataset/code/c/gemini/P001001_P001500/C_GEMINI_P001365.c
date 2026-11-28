#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dfsGold(int** grid, int m, int n, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
    int gold = grid[r][c];
    grid[r][c] = 0;

    int maxSub = MAX(
        MAX(dfsGold(grid, m, n, r + 1, c), dfsGold(grid, m, n, r - 1, c)),
        MAX(dfsGold(grid, m, n, r, c + 1), dfsGold(grid, m, n, r, c - 1))
    );

    grid[r][c] = gold;
    return gold + maxSub;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                maxGold = MAX(maxGold, dfsGold(grid, m, n, i, j));
            }
        }
    }
    return maxGold;
}