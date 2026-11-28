#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 505
char bank[MAX_N][16];
char start_gene[16], end_gene[16];
bool vis[MAX_N];
int q[MAX_N], q_dist[MAX_N];
bool diff_one(const char* a, const char* b) {
    int diff = 0;
    for (int i = 0; i < 8; i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff == 1;
}
int main() {
    int n;
    if (scanf("%15s %15s %d", start_gene, end_gene, &n) == 3) {
        int end_idx = -1;
        for (int i = 0; i < n; i++) {
            scanf("%15s", bank[i]);
            if (strcmp(bank[i], end_gene) == 0) end_idx = i;
            vis[i] = false;
        }
        if (end_idx == -1) { printf("-1\n"); return 0; }
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) {
            if (diff_one(start_gene, bank[i])) {
                vis[i] = true;
                q[tail] = i; q_dist[tail++] = 1;
            }
        }
        int ans = -1;
        while (head < tail) {
            int cur = q[head];
            int dist = q_dist[head++];
            if (cur == end_idx) { ans = dist; break; }
            for (int i = 0; i < n; i++) {
                if (!vis[i] && diff_one(bank[cur], bank[i])) {
                    vis[i] = true;
                    q[tail] = i; q_dist[tail++] = dist + 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}