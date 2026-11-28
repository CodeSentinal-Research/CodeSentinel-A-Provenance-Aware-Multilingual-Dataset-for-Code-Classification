#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 5005
char words[MAX_N][32];
char begin_word[32], end_word[32];
bool vis[MAX_N];
int q[MAX_N], q_dist[MAX_N];
bool is_diff_one(const char* a, const char* b) {
    int diff = 0;
    for (int i = 0; a[i] && b[i]; i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}
int main() {
    int n;
    if (scanf("%31s %31s %d", begin_word, end_word, &n) == 3) {
        int end_idx = -1;
        for (int i = 0; i < n; i++) {
            scanf("%31s", words[i]);
            if (strcmp(words[i], end_word) == 0) end_idx = i;
            vis[i] = false;
        }
        if (end_idx == -1) { printf("0\n"); return 0; }
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) {
            if (is_diff_one(begin_word, words[i])) {
                vis[i] = true;
                q[tail] = i; q_dist[tail++] = 2;
            }
        }
        int ans = 0;
        while (head < tail) {
            int cur = q[head];
            int dist = q_dist[head++];
            if (cur == end_idx) { ans = dist; break; }
            for (int i = 0; i < n; i++) {
                if (!vis[i] && is_diff_one(words[cur], words[i])) {
                    vis[i] = true;
                    q[tail] = i; q_dist[tail++] = dist + 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}