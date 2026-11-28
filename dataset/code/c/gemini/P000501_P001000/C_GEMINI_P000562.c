#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 1005
int rooms[MAX_N][MAX_N];
int room_len[MAX_N];
bool vis[MAX_N];
int q[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &room_len[i]);
            for (int j = 0; j < room_len[i]; j++) {
                scanf("%d", &rooms[i][j]);
            }
        }
        memset(vis, 0, sizeof(vis));
        int head = 0, tail = 0;
        q[tail++] = 0;
        vis[0] = true;
        int count = 1;
        while (head < tail) {
            int r = q[head++];
            for (int j = 0; j < room_len[r]; j++) {
                int key = rooms[r][j];
                if (!vis[key]) {
                    vis[key] = true;
                    count++;
                    q[tail++] = key;
                }
            }
        }
        printf("%s\n", count == n ? "true" : "false");
    }
    return 0;
}