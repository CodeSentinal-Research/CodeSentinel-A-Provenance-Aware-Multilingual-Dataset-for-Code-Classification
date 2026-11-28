/*
 * P001550: Sum of Absolute Differences in Each Window
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

static void solve_sum_of_absolute_differences_in_each_window(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    long long ans = 0, x;
    for (int i = 0; i < n; ++i) { scanf("%lld", &x); ans += x; }
    printf("%lld\n", ans);
}

int main(void) {
    solve_sum_of_absolute_differences_in_each_window();
    return 0;
}
