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
    long long cur = 0, best = -9223372036854775807LL; for (int i = 0; i < n; i++) { cur = (cur + a[i] > a[i]) ? cur + a[i] : a[i]; if (cur > best) best = cur; } printf("%lld\n", n ? best : 0);
    return 0;
}
