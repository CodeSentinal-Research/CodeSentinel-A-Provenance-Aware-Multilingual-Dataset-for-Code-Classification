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
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) printf("%lld%s", a[i][j], (i == r - 1 && j == c - 1) ? "\n" : " ");
    return 0;
}
