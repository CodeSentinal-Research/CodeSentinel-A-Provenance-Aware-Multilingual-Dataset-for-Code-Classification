/*
 * P001595: Sum Between Two Positions
 * Category: Prefix Sum
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

static void solve_sum_between_two_positions(void) {
    int n;
    long long target;
    if (scanf("%d %lld", &n, &target) != 2) return;
    long long *a = malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp_ll_asc);
    int l = 0, r = n - 1, ok = 0;
    while (l < r) { long long s = a[l] + a[r]; if (s == target) { ok = 1; break; } if (s < target) ++l; else --r; }
    printf("%s\n", ok ? "YES" : "NO");
    free(a);
}

int main(void) {
    solve_sum_between_two_positions();
    return 0;
}
