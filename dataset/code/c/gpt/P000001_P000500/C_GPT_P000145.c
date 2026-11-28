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
    long long key; if (scanf("%lld", &key) != 1) key = 0; int found = 0; for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (a[i][j] == key) found = 1; printf("%s\n", found ? "Yes" : "No");
    return 0;
}
