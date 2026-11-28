#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m, r, c;
    if (scanf("%d %d %d %d", &n, &m, &r, &c) == 4) {
        int ans = MAX(r - 1, n - r) + MAX(c - 1, m - c);
        printf("%d\n", ans);
    }
    return 0;
}