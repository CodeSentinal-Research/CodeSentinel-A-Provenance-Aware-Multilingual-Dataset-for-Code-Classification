#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) { int x; scanf("%d", &x); }
        int q; scanf("%d", &q);
        while (q--) {
            int l, r; scanf("%d %d", &l, &r);
            printf("%d\n", r - l + 1);
        }
    }
    return 0;
}