int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int ans = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int equal = 1;
            for (int i = 0; i < n; i++) {
                if (grid[r][i] != grid[i][c]) {
                    equal = 0;
                    break;
                }
            }
            if (equal) ans++;
        }
    }
    return ans;
}