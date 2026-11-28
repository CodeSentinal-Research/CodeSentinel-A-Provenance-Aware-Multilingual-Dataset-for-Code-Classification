#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 0) { printf("-1\n"); return 0; }
        int max_v; scanf("%d", &max_v);
        for (int i = 1; i < n; i++) {
            int x; scanf("%d", &x);
            if (x > max_v) max_v = x;
        }
        printf("%d\n", max_v);
    } else {
        printf("-1\n");
    }
    return 0;
}