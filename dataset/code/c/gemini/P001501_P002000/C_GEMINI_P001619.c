#include <stdio.h>

int main() {
    int n, l, r;
    if (scanf("%d %d %d", &n, &l, &r) == 3) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i >= l && i <= r) ans ^= x;
        }
        printf("%d\n", ans);
    }
    return 0;
}