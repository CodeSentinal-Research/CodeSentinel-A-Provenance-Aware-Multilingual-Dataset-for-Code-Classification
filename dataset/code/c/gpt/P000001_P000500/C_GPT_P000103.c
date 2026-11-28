#include <stdio.h>
#include <stdlib.h>

static int cmp_asc(const void *pa, const void *pb) {
    long long a = *(const long long *)pa, b = *(const long long *)pb;
    return (a > b) - (a < b);
}

static int cmp_desc(const void *pa, const void *pb) {
    long long a = *(const long long *)pa, b = *(const long long *)pb;
    return (b > a) - (b < a);
}

static void print_array(long long a[], int n) {
    for (int i = 0; i < n; i++) printf("%lld%s", a[i], i + 1 == n ? "\n" : " ");
    if (n == 0) printf("\n");
}

int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long s = 0; for (int i = 0; i < n; i++) s += a[i]; printf("%lld\n", s);
    return 0;
}
