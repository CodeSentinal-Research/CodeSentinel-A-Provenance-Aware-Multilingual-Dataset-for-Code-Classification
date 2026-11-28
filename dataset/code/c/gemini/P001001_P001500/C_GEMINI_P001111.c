#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int moves;
    if (scanf("%d", &moves) == 1) {
        int board[31];
        memset(board, -1, sizeof(board));
        for (int i = 0; i < moves; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            board[u] = v;
        }
        bool vis[31] = {false};
        int q_pos[100], q_step[100];
        int head = 0, tail = 0;
        q_pos[tail] = 1;
        q_step[tail++] = 0;
        vis[1] = true;
        int ans = -1;

        while (head < tail) {
            int pos = q_pos[head];
            int steps = q_step[head++];
            if (pos == 30) {
                ans = steps;
                break;
            }
            for (int d = 1; d <= 6; d++) {
                int next = pos + d;
                if (next <= 30) {
                    if (board[next] != -1) next = board[next];
                    if (!vis[next]) {
                        vis[next] = true;
                        q_pos[tail] = next;
                        q_step[tail++] = steps + 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}