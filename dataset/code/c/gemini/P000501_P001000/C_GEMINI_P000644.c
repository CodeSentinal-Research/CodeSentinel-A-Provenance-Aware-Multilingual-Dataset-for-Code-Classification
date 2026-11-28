#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int x, y; scanf("%d %d", &x, &y);
        int ix = -1, iy = -1;
        for (int i = 0; i < n; i++) {
            if (vals[i] == x && ix == -1) ix = i;
            if (vals[i] == y && iy == -1) iy = i;
        }
        if (ix != -1 && iy != -1) {
            int tmp = vals[ix]; vals[ix] = vals[iy]; vals[iy] = tmp;
        }
        for (int i = 0; i < n; i++) printf("%d%s", vals[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}