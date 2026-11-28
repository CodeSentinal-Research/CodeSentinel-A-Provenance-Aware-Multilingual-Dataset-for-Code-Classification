#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 100005
int res[MAX_N], q[MAX_N];
bool banned[MAX_N], vis[MAX_N];
int main() {
    int n, p, b;
    if (scanf("%d %d %d", &n, &p, &b) == 3) {
        memset(banned, 0, sizeof(banned));
        for (int i = 0; i < b; i++) {
            int x; scanf("%d", &x);
            banned[x] = true;
        }
        int k; scanf("%d", &k);
        for (int i = 0; i < n; i++) { res[i] = -1; vis[i] = false; }
        res[p] = 0; vis[p] = true;
        int head = 0, tail = 0;
        q[tail++] = p;
        while (head < tail) {
            int cur = q[head++];
            int min_idx = (cur - k + 1 > k - 1 - cur) ? cur - k + 1 : k - 1 - cur;
            int max_idx = (cur + k - 1 < 2 * n - k - 1 - cur) ? cur + k - 1 : 2 * n - k - 1 - cur;
            for (int nxt = min_idx; nxt <= max_idx; nxt += 2) {
                if (nxt >= 0 && nxt < n && !banned[nxt] && !vis[nxt]) {
                    vis[nxt] = true;
                    res[nxt] = res[cur] + 1;
                    q[tail++] = nxt;
                }
            }
        }
        for (int i = 0; i < n; i++) printf("%d%s", res[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}