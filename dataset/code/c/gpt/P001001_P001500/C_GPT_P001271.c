/*
 * P001271: Minimum Number of Taps to Water a Garden
 * Category: Greedy
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

static void solve_minimum_number_of_taps_to_water_a_garden(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    long long x, best = LLONG_MAX;
    for (int i = 0; i < n; ++i) { scanf("%lld", &x); if (x < best) best = x; }
    printf("%lld\n", best == LLONG_MAX ? 0 : best);
}

int main(void) {
    solve_minimum_number_of_taps_to_water_a_garden();
    return 0;
}
