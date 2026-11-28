#include <stdio.h>
#include <string.h>
#define MAX_N 100005
int q[MAX_N];
int counts[MAX_N * 2]; // simplified direct count for tests
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) {
            int v; scanf("%d", &v);
            q[tail++] = v;
        }
        int q_count;
        scanf("%d", &q_count);
        while (q_count--) {
            char cmd[32];
            scanf("%31s", cmd);
            if (strcmp(cmd, "showFirstUnique") == 0) {
                int ans = -1;
                for (int i = head; i < tail; i++) {
                    int c = 0;
                    for (int j = 0; j < tail; j++) {
                        if (q[j] == q[i]) c++;
                    }
                    if (c == 1) { ans = q[i]; break; }
                }
                printf("%d\n", ans);
            } else if (strcmp(cmd, "add") == 0) {
                int val; scanf("%d", &val);
                q[tail++] = val;
            }
        }
    }
    return 0;
}