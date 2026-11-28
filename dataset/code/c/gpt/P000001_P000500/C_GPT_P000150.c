#include <stdio.h>
#include <stdlib.h>

static int cmp_asc(const void *pa, const void *pb) {
    long long a = *(const long long *)pa, b = *(const long long *)pb;
    return (a > b) - (a < b);
}

int main(void) {
    int r, c;
    long long a[100][100];
    if (scanf("%d %d", &r, &c) != 2) return 1;
    if (r > 100) r = 100;
    if (c > 100) c = 100;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%lld", &a[i][j]);
    long long flat[10000]; int n = 0; for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) flat[n++] = a[i][j]; qsort(flat, n, sizeof(long long), cmp_asc); for (int i = 0; i < n; i++) printf("%lld%s", flat[i], i + 1 == n ? "\n" : " ");
    return 0;
}
