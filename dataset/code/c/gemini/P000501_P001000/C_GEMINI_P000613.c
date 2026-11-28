#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N], res[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            int found = 0;
            for (int j = 0; j < cnt; j++) if (res[j] == x) { found = 1; break; }
            if (!found) res[cnt++] = x;
        }
        for (int i = 0; i < cnt; i++) printf("%d%s", res[i], i == cnt - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}