/*
 * P001002: Check Max Heap Property
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

static void solve_check_max_heap_property(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    long long *a = malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    int ok = 1;
    for (int i = 0; i < n; ++i) {
        int l = 2 * i + 1, r = l + 1;
        if ((l < n && a[i] < a[l]) || (r < n && a[i] < a[r])) ok = 0;
    }
    printf("%s\n", ok ? "YES" : "NO");
    free(a);
}

int main(void) {
    solve_check_max_heap_property();
    return 0;
}
