#include <stdio.h>
#include <stdlib.h>

// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
long long extGcd(long long a, long long b, long long* x, long long* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extGcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

int cmp(const void* a, const void* b) {
    long long diff = *(long long*)a - *(long long*)b;
    return (diff > 0) - (diff < 0);
}

int main() {
    long long a, b, m;
    if (scanf("%lld %lld %lld", &a, &b, &m) == 3) {
        long long x, y;
        long long g = extGcd(a, m, &x, &y);
        if (b % g != 0) {
            printf("-1\n");
        } else {
            long long x0 = (x * (b / g)) % m;
            x0 = (x0 + m) % m;
            long long step = m / g;
            long long* ans = (long long*)malloc(g * sizeof(long long));
            for (int i = 0; i < g; i++) {
                ans[i] = (x0 + i * step) % m;
            }
            qsort(ans, g, sizeof(long long), cmp);
            for (int i = 0; i < g; i++) {
                printf("%lld%s", ans[i], (i == g - 1 ? "" : " "));
            }
            printf("\n");
            free(ans);
        }
    }
    return 0;
}