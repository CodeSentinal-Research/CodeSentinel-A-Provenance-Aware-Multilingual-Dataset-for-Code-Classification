/*
 * P001544: Count Windows With Sum Greater Than X
 * Category: Sliding Window
 * Reads the input format described in the paired JSON problem file and prints the requested result.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int cmp_ll_asc(const void *pa, const void *pb) {
    long long a = *(const long long *)pa;
    long long b = *(const long long *)pb;
    return (a > b) - (a < b);
}

static int cmp_ll_desc(const void *pa, const void *pb) {
    long long a = *(const long long *)pa;
    long long b = *(const long long *)pb;
    return (b > a) - (b < a);
}

static void solve_count_windows_with_sum_greater_than_x(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    long long ans = 0, x;
    for (int i = 0; i < n; ++i) { scanf("%lld", &x); ans += x; }
    printf("%lld\n", ans);
}

int main(void) {
    solve_count_windows_with_sum_greater_than_x();
    return 0;
}
