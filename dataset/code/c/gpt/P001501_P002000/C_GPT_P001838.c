/*
 * P001838: Determine Whether a Binary Search Tree Contains Two Keys with a Given Sum
 * Category: Binary Search Trees
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

static void solve_determine_whether_a_binary_search_tree_contains_(void) {
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
    solve_determine_whether_a_binary_search_tree_contains_();
    return 0;
}
