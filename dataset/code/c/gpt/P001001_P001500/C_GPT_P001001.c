/*
 * P001001: Find the Kth Largest Element
 * Category: Heap
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

static void solve_find_the_kth_largest_element(void) {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return;
    long long *a = malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp_ll_desc);
    printf("%lld\n", a[k - 1]);
    free(a);
}

int main(void) {
    solve_find_the_kth_largest_element();
    return 0;
}
