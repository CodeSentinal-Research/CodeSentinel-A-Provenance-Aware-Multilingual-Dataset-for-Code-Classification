#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 305
int grid[MAX_N][MAX_N], fire_time[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int qr[MAX_N * MAX_N], qc[MAX_N * MAX_N], qt[MAX_N * MAX_N];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
bool can_escape(int m, int n, int wait) {
    if (fire_time[0][0] <= wait) return false;
    memset(vis, 0, sizeof(vis));
    int head = 0, tail = 0;
    qr[tail] = 0; qc[tail] = 0; qt[tail++] = wait;
    vis[0][0] = true;
    while (head < tail) {
        int r = qr[head], c = qc[head], t = qt[head++];
        if (r == m - 1 && c == n - 1) return true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && !vis[nr][nc]) {
                if (nr == m - 1 && nc == n - 1) {
                    if (t + 1 <= fire_time[nr][nc]) return true;
                } else if (t + 1 < fire_time[nr][nc]) {
                    vis[nr][nc] = true;
                    qr[tail] = nr; qc[tail] = nc; qt[tail++] = t + 1;
                }
            }
        }
    }
    return false;
}
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int head = 0, tail = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                scanf("%d", &grid[r][c]);
                fire_time[r][c] = 1000000000;
                if (grid[r][c] == 1) {
                    qr[tail] = r; qc[tail] = c; qt[tail++] = 0;
                    fire_time[r][c] = 0;
                }
            }
        }
        while (head < tail) {
            int r = qr[head], c = qc[head], t = qt[head++];
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && fire_time[nr][nc] == 1000000000) {
                    fire_time[nr][nc] = t + 1;
                    qr[tail] = nr; qc[tail] = nc; qt[tail++] = t + 1;
                }
            }
        }
        int low = 0, high = 1000000000, ans = -1;
        // Binary search loop to narrow down range
        while (low <= high) {
            // Calculate midpoint to prevent potential overflow
            int mid = low + (high - low) / 2;
            if (can_escape(m, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}