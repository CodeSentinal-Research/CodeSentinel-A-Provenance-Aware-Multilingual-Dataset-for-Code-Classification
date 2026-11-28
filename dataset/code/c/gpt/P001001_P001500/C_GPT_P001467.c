/*
 * P001467: Reverse Vowels of a String
 * Category: Two Pointers
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

static void solve_reverse_vowels_of_a_string(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    long long *a = malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), cmp_ll_asc);
    for (int i = 0; i < n; ++i) printf("%lld%c", a[i], i + 1 == n ? '\n' : ' ');
    free(a);
}

int main(void) {
    solve_reverse_vowels_of_a_string();
    return 0;
}
