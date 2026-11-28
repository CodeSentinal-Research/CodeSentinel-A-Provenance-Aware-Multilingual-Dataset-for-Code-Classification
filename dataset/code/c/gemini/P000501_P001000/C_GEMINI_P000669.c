#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 0) { printf("-1\n"); return 0; }
        int min_v; scanf("%d", &min_v);
        for (int i = 1; i < n; i++) {
            int x; scanf("%d", &x);
            if (x < min_v) min_v = x;
        }
        printf("%d\n", min_v);
    } else {
        printf("-1\n");
    }
    return 0;
}