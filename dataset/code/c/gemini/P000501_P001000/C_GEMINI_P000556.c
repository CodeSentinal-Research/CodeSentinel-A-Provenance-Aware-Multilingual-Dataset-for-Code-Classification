#include <stdio.h>
#define MAX_M 1005
#define MAX_N 1005
int grid[MAX_M][MAX_N], dist[MAX_M][MAX_N];
int max_r[MAX_M], max_c[MAX_N];
int qr[MAX_M * MAX_N], qc[MAX_M * MAX_N];
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &grid[i][j]);
                dist[i][j] = 1000000000;
            }
            max_r[i] = 0;
        }
        for (int j = 0; j < n; j++) max_c[j] = 0;
        if (m == 1 && n == 1) { printf("1\n"); return 0; }
        dist[0][0] = 1;
        int head = 0, tail = 0;
        qr[tail] = 0; qc[tail++] = 0;
        while (head < tail) {
            int r = qr[head], c = qc[head++];
            int d = dist[r][c], k = grid[r][c];
            int start_c = (c + 1 > max_r[r] + 1) ? c + 1 : max_r[r] + 1;
            int end_c = (c + k < n - 1) ? c + k : n - 1;
            for (int nc = start_c; nc <= end_c; nc++) {
                if (dist[r][nc] == 1000000000) {
                    dist[r][nc] = d + 1;
                    if (r == m - 1 && nc == n - 1) { printf("%d\n", d + 1); return 0; }
                    qr[tail] = r; qc[tail++] = nc;
                }
            }
            if (end_c > max_r[r]) max_r[r] = end_c;
            int start_r = (r + 1 > max_c[c] + 1) ? r + 1 : max_c[c] + 1;
            int end_r = (r + k < m - 1) ? r + k : m - 1;
            for (int nr = start_r; nr <= end_r; nr++) {
                if (dist[nr][c] == 1000000000) {
                    dist[nr][c] = d + 1;
                    if (nr == m - 1 && c == n - 1) { printf("%d\n", d + 1); return 0; }
                    qr[tail] = nr; qc[tail++] = c;
                }
            }
            if (end_r > max_c[c]) max_c[c] = end_r;
        }
        printf("%d\n", dist[m - 1][n - 1] != 1000000000 ? dist[m - 1][n - 1] : -1);
    }
    return 0;
}