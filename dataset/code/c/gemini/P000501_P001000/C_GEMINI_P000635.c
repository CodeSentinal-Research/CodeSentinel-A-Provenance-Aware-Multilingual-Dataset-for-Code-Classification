#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N], groups[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int g; scanf("%d", &g);
        for (int i = 0; i < g; i++) scanf("%d", &groups[i]);
        int cur = 0;
        for (int i = 0; i < g; i++) {
            int sz = groups[i];
            if (cur + sz <= n) {
                int l = cur, r = cur + sz - 1;
                while (l < r) {
                    int tmp = vals[l]; vals[l] = vals[r]; vals[r] = tmp;
                    l++; r--;
                }
                cur += sz;
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++) printf("%d%s", vals[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}