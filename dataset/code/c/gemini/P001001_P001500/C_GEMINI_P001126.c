#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize) {
    int m = heightsSize, n = heightsColSize[0];
    int dist[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) dist[i][j] = INT_MAX;
    }
    dist[0][0] = 0;

    int q_r[100005], q_c[100005], q_d[100005];
    int head = 0, tail = 0;
    q_r[tail] = 0; q_c[tail] = 0; q_d[tail++] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (head < tail) {
        int r = q_r[head], c = q_c[head], d = q_d[head++];
        if (d > dist[r][c]) continue;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int diff = abs(heights[nr][nc] - heights[r][c]);
                int effort = d > diff ? d : diff;
                if (effort < dist[nr][nc]) {
                    dist[nr][nc] = effort;
                    q_r[tail] = nr; q_c[tail] = nc; q_d[tail++] = effort;
                }
            }
        }
    }
    return dist[m - 1][n - 1];
}