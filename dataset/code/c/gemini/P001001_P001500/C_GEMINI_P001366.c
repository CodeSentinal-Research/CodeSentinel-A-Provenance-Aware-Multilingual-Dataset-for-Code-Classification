int dfsPaths(int** grid, int m, int n, int r, int c, int count, int empty) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] < 0) return 0;
    if (grid[r][c] == 2) return count == empty + 1 ? 1 : 0;

    int temp = grid[r][c];
    grid[r][c] = -2;

    int paths = dfsPaths(grid, m, n, r + 1, c, count + 1, empty) +
                dfsPaths(grid, m, n, r - 1, c, count + 1, empty) +
                dfsPaths(grid, m, n, r, c + 1, count + 1, empty) +
                dfsPaths(grid, m, n, r, c - 1, count + 1, empty);

    grid[r][c] = temp;
    return paths;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int empty = 0, startR = 0, startC = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                startR = i; startC = j;
            } else if (grid[i][j] == 0) {
                empty++;
            }
        }
    }
    return dfsPaths(grid, m, n, startR, startC, 0, empty);
}