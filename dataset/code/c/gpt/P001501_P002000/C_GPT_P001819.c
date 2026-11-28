/*
 * P001819: Determine the Rank of a Key in a Binary Search Tree
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

static void solve_determine_the_rank_of_a_key_in_a_binary_search_t(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    long long *a = malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp_ll_asc);
    for (int i = 0; i < n; ++i) printf("%lld%c", a[i], i + 1 == n ? '\n' : ' ');
    free(a);
}

int main(void) {
    solve_determine_the_rank_of_a_key_in_a_binary_search_t();
    return 0;
}
