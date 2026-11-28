#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int w, h, n;
    scanf("%d%d%d", &w, &h, &n);
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    x[n] = w;
    y[n] = h;
    qsort(x, n + 1, sizeof(int), cmp);
    qsort(y, n + 1, sizeof(int), cmp);
    int max_dx = 0, max_dy = 0;
    for (int i = 1; i <= n; i++) {
        int dx = x[i] - x[i - 1] - 1;
        int dy = y[i] - y[i - 1] - 1;
        if (dx > max_dx) max_dx = dx;
        if (dy > max_dy) max_dy = dy;
    }
    printf("%d\n", max_dx * max_dy);
    return 0;
}
