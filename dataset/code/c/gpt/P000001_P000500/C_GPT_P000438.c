#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXN 1005
#define MAXS 4096

static void print_ints(long long a[], int n) {
    for (int i = 0; i < n; i++) printf("%lld%s", a[i], i + 1 == n ? "\n" : " ");
    if (n == 0) printf("\n");
}

static int cmp_ll(const void *x, const void *y) {
    long long a = *(const long long *)x, b = *(const long long *)y;
    return (a > b) - (a < b);
}

static long long gcd_ll(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { long long t = a % b; a = b; b = t; }
    return a;
}

/* Find Ceiling in Sorted Array */
int main(void) {
    int n; long long x; if (scanf("%d%lld", &n, &x) < 1) return 0; long long a[MAXN]; for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) if(a[i]==x){printf("%d\n", i); return 0;} printf("-1\n");

    return 0;
}
