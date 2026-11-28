#include <stdio.h>
#include <stdlib.h>

int dfsGrid(int** grid, int r, int c, int cur, int target, int m, int n) {
    if (r >= m || c >= n) return 0;
    cur += grid[r][c];
    if (r == m - 1 && c == n - 1) return cur == target ? 1 : 0;
    return dfsGrid(grid, r + 1, c, cur, target, m, n) + dfsGrid(grid, r, c + 1, cur, target, m, n);
}

int main() {
    int m, n, target;
    if (scanf("%d %d %d", &m, &n, &target) == 3) {
        int** grid = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            grid[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) scanf("%d", &grid[i][j]);
        }
        printf("%d\n", dfsGrid(grid, 0, 0, 0, target, m, n));
        for (int i = 0; i < m; i++) free(grid[i]);
        free(grid);
    }
    return 0;
}