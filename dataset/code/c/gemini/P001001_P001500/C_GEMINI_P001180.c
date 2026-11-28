#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        for (int i = 1; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            int na = x + MAX(b, c);
            int nb = y + MAX(a, c);
            int nc = z + MAX(a, b);
            a = na; b = nb; c = nc;
        }
        printf("%d\n", MAX(a, MAX(b, c)));
    }
    return 0;
}