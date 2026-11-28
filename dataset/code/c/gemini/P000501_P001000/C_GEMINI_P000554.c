#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 1005
char maze[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int qr[MAX_N * MAX_N], qc[MAX_N * MAX_N], qd[MAX_N * MAX_N];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        for (int i = 0; i < m; i++) scanf("%s", maze[i]);
        int er, ec;
        scanf("%d %d", &er, &ec);
        memset(vis, 0, sizeof(vis));
        int head = 0, tail = 0;
        qr[tail] = er; qc[tail] = ec; qd[tail++] = 0;
        vis[er][ec] = true;
        int ans = -1;
        while (head < tail) {
            int r = qr[head], c = qc[head], d = qd[head++];
            if ((r != er || c != ec) && (r == 0 || r == m - 1 || c == 0 || c == n - 1)) {
                ans = d; break;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.' && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    qr[tail] = nr; qc[tail] = nc; qd[tail++] = d + 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}