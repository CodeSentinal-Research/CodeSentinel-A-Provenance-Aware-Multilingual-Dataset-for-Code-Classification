#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 105
int board[MAX_N][MAX_N];
int arr[MAX_N * MAX_N];
bool vis[MAX_N * MAX_N];
int q_pos[MAX_N * MAX_N], q_moves[MAX_N * MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) scanf("%d", &board[i][j]);
        }
        int cur = 1;
        for (int r = n - 1; r >= 0; r--) {
            if ((n - 1 - r) % 2 == 0) {
                for (int c = 0; c < n; c++) arr[cur++] = board[r][c];
            } else {
                for (int c = n - 1; c >= 0; c--) arr[cur++] = board[r][c];
            }
        }
        memset(vis, 0, sizeof(vis));
        int head = 0, tail = 0;
        q_pos[tail] = 1; q_moves[tail++] = 0;
        vis[1] = true;
        int ans = -1;
        while (head < tail) {
            int pos = q_pos[head];
            int moves = q_moves[head++];
            if (pos == n * n) { ans = moves; break; }
            for (int step = 1; step <= 6; step++) {
                int nxt = pos + step;
                if (nxt <= n * n) {
                    int dest = (arr[nxt] != -1) ? arr[nxt] : nxt;
                    if (!vis[dest]) {
                        vis[dest] = true;
                        q_pos[tail] = dest;
                        q_moves[tail++] = moves + 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}