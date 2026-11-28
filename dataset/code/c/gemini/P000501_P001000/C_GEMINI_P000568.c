#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool vis[610][610];
int qr[400000], qc[400000], qd[400000];
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main() {
    int x, y;
    if (scanf("%d %d", &x, &y) == 2) {
        x = abs(x); y = abs(y);
        memset(vis, 0, sizeof(vis));
        int head = 0, tail = 0;
        qr[tail] = 0; qc[tail] = 0; qd[tail++] = 0;
        vis[4][4] = true;
        int ans = 0;
        while (head < tail) {
            int r = qr[head], c = qc[head], d = qd[head++];
            if (r == x && c == y) { ans = d; break; }
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= -2 && nr <= x + 2 && nc >= -2 && nc <= y + 2) {
                    if (!vis[nr + 4][nc + 4]) {
                        vis[nr + 4][nc + 4] = true;
                        qr[tail] = nr; qc[tail] = nc; qd[tail++] = d + 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}