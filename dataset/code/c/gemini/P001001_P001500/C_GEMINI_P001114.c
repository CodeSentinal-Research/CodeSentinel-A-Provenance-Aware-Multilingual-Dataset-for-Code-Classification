#include <stdio.h>
#include <stdlib.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int q_r[m * n + 5], q_c[m * n + 5], q_d[m * n + 5];
    int head = 0, tail = 0;
    int fresh = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q_r[tail] = i; q_c[tail] = j; q_d[tail++] = 0;
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (head < tail) {
        int r = q_r[head], c = q_c[head], d = q_d[head++];
        if (d > minutes) minutes = d;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                grid[nr][nc] = 2;
                fresh--;
                q_r[tail] = nr; q_c[tail] = nc; q_d[tail++] = d + 1;
            }
        }
    }
    return fresh == 0 ? minutes : -1;
}