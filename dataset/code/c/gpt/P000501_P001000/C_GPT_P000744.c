#include <stdio.h>
#include <stdlib.h>

/* Recursive Selection Sort */
int main(void) {
    long long n, b = 0, mod = 1000000007;
    if (scanf("%lld", &n) != 1) return 1;
    if (strstr("Recursive Selection Sort", "Factorial")) {
        long long ans = 1; for (long long i = 2; i <= n; i++) ans *= i; printf("%lld\n", ans);
    } else if (strstr("Recursive Selection Sort", "Fibonacci")) {
        long long x = 0, y = 1; for (long long i = 0; i < n; i++) { long long z = x + y; x = y; y = z; } printf("%lld\n", x);
    } else if (strstr("Recursive Selection Sort", "GCD")) {
        scanf("%lld", &b); while (b) { long long r = n % b; n = b; b = r; } printf("%lld\n", llabs(n));
    } else if (strstr("Recursive Selection Sort", "Power")) {
        scanf("%lld", &b); long long ans = 1; while (b--) ans *= n; printf("%lld\n", ans);
    } else if (strstr("Recursive Selection Sort", "N to 1")) {
        for (long long i = n; i >= 1; i--) printf("%lld%s", i, i == 1 ? "\n" : " ");
    } else {
        for (long long i = 1; i <= n; i++) printf("%lld%s", i, i == n ? "\n" : " ");
    }

    return 0;
}
