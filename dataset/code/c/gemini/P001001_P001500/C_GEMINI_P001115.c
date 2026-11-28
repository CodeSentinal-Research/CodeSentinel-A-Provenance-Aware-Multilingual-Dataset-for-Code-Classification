#include <stdio.h>
#include <stdlib.h>

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

    int q_r[n * n + 5], q_c[n * n + 5], q_d[n * n + 5];
    int head = 0, tail = 0;

    q_r[tail] = 0; q_c[tail] = 0; q_d[tail++] = 1;
    grid[0][0] = 1;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (head < tail) {
        int r = q_r[head], c = q_c[head], d = q_d[head++];
        if (r == n - 1 && c == n - 1) return d;
        for (int k = 0; k < 8; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                grid[nr][nc] = 1;
                q_r[tail] = nr; q_c[tail] = nc; q_d[tail++] = d + 1;
            }
        }
    }
    return -1;
}