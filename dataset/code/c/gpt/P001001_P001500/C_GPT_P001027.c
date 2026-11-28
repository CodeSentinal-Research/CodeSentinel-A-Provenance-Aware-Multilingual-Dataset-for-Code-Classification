/*
 * P001027: Print Heap Level Order
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

static void solve_print_heap_level_order(void) {
    long long n;
    if (scanf("%lld", &n) != 1) return;
    int height = 0;
    while (n > 1) { n >>= 1; ++height; }
    printf("%d\n", height);
}

int main(void) {
    solve_print_heap_level_order();
    return 0;
}
