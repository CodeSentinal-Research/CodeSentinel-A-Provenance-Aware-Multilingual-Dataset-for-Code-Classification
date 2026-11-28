#include <stdio.h>
#define MAX_N 1005
int grid[MAX_N][MAX_N];
int qr[MAX_N * MAX_N], qc[MAX_N * MAX_N], qd[MAX_N * MAX_N];
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int head = 0, tail = 0, fresh = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                scanf("%d", &grid[r][c]);
                if (grid[r][c] == 2) {
                    qr[tail] = r; qc[tail] = c; qd[tail] = 0; tail++;
                } else if (grid[r][c] == 1) fresh++;
            }
        }
        int mins = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while (head < tail) {
            int r = qr[head], c = qc[head], d = qd[head++];
            if (d > mins) mins = d;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    qr[tail] = nr; qc[tail] = nc; qd[tail] = d + 1; tail++;
                }
            }
        }
        printf("%d\n", fresh == 0 ? mins : -1);
    }
    return 0;
}