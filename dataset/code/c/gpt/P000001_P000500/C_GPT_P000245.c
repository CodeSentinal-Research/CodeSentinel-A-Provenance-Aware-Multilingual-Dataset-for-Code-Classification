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

/* Print Lower Triangular Matrix */
int main(void) {
    int r,c; if(scanf("%d%d",&r,&c)<2) return 0; long long a[105][105]; for(int i=0;i<r;i++) for(int j=0;j<c;j++) scanf("%lld",&a[i][j]); for(int i=0;i<r;i++){ for(int j=0;j<c;j++) printf("%lld%s", a[i][j], j+1==c ? "\n" : " "); }

    return 0;
}
