#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int w, h, n;
    if (scanf("%d %d %d", &w, &h, &n) == 3) {
        int* xs = (int*)malloc((n + 2) * sizeof(int));
        int* ys = (int*)malloc((n + 2) * sizeof(int));
        xs[0] = 0; xs[n + 1] = w + 1;
        ys[0] = 0; ys[n + 1] = h + 1;

        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &xs[i], &ys[i]);
        }

        qsort(xs, n + 2, sizeof(int), cmpInt);
        qsort(ys, n + 2, sizeof(int), cmpInt);

        int maxDx = 0, maxDy = 0;
        for (int i = 1; i < n + 2; i++) {
            maxDx = MAX(maxDx, xs[i] - xs[i - 1] - 1);
            maxDy = MAX(maxDy, ys[i] - ys[i - 1] - 1);
        }
        printf("%lld\n", (long long)maxDx * maxDy);
        free(xs);
        free(ys);
    }
    return 0;
}