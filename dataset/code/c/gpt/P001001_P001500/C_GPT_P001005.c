/*
 * P001005: Count Leaf Nodes in a Heap
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

static void solve_count_leaf_nodes_in_a_heap(void) {
    long long n;
    if (scanf("%lld", &n) != 1) return;
    printf("%lld\n", (n + 1) / 2);
}

int main(void) {
    solve_count_leaf_nodes_in_a_heap();
    return 0;
}
