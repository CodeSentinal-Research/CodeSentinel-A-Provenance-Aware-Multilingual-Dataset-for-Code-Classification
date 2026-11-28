#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 105
int grid[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N][2];
int qr[MAX_N * MAX_N * 2], qc[MAX_N * MAX_N * 2], qs[MAX_N * MAX_N * 2], qd[MAX_N * MAX_N * 2];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) scanf("%d", &grid[i][j]);
        }
        memset(vis, 0, sizeof(vis));
        int head = 0, tail = 0;
        qr[tail] = 0; qc[tail] = 0; qs[tail] = 0; qd[tail++] = 0;
        vis[0][0][0] = true;
        int ans = -1;
        while (head < tail) {
            int r = qr[head], c = qc[head], s = qs[head], d = qd[head++];
            if (s == 0 && r == n - 1 && c == n - 2) { ans = d; break; }
            if (s == 0) {
                if (c + 2 < n && grid[r][c + 2] == 0 && !vis[r][c + 1][0]) {
                    vis[r][c + 1][0] = true;
                    qr[tail] = r; qc[tail] = c + 1; qs[tail] = 0; qd[tail++] = d + 1;
                }
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r + 1][c][0]) {
                    vis[r + 1][c][0] = true;
                    qr[tail] = r + 1; qc[tail] = c; qs[tail] = 0; qd[tail++] = d + 1;
                }
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][1]) {
                    vis[r][c][1] = true;
                    qr[tail] = r; qc[tail] = c; qs[tail] = 1; qd[tail++] = d + 1;
                }
            } else {
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c + 1][1]) {
                    vis[r][c + 1][1] = true;
                    qr[tail] = r; qc[tail] = c + 1; qs[tail] = 1; qd[tail++] = d + 1;
                }
                if (r + 2 < n && grid[r + 2][c] == 0 && !vis[r + 1][c][1]) {
                    vis[r + 1][c][1] = true;
                    qr[tail] = r + 1; qc[tail] = c; qs[tail] = 1; qd[tail++] = d + 1;
                }
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][0]) {
                    vis[r][c][0] = true;
                    qr[tail] = r; qc[tail] = c; qs[tail] = 0; qd[tail++] = d + 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}