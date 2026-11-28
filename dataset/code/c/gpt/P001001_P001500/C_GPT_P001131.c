/*
 * P001131: Fibonacci Number
 * Category: Dynamic Programming
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

static void solve_fibonacci_number(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    long long a = 0, b = 1;
    for (int i = 0; i < n; ++i) { long long c = a + b; a = b; b = c; }
    printf("%lld\n", a);
}

int main(void) {
    solve_fibonacci_number();
    return 0;
}
