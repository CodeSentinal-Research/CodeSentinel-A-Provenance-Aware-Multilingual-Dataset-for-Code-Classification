#include <stdio.h>
#include <string.h>
#define MAX_N 1005
int res[MAX_N];
int st[10005];
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) res[i] = 0;
        int top = -1, prev_time = 0;
        for (int i = 0; i < m; i++) {
            char log[128];
            scanf("%127s", log);
            int fid, time;
            char typ[16];
            sscanf(log, "%d:%[^:]:%d", &fid, typ, &time);
            if (strcmp(typ, "start") == 0) {
                if (top >= 0) res[st[top]] += time - prev_time;
                st[++top] = fid;
                prev_time = time;
            } else {
                res[st[top--]] += time - prev_time + 1;
                prev_time = time + 1;
            }
        }
        for (int i = 0; i < n; i++) printf("%d%s", res[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}