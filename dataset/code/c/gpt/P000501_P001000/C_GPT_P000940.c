#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Misère Nim */
int main(void) {
    long long a, b = 0, m = 1000000007;
    if (scanf("%lld", &a) != 1) return 1;
    scanf("%lld %lld", &b, &m);
    if (strstr("TITLE", "Reverse")) { long long x = llabs(a), rev = 0; while (x) { rev = rev * 10 + x % 10; x /= 10; } printf("%lld\n", a < 0 ? -rev : rev); }
    else if (strstr("TITLE", "Palindrome")) { long long x = llabs(a), rev = 0, y = x; while (y) { rev = rev * 10 + y % 10; y /= 10; } printf("%s\n", rev == x ? "Yes" : "No"); }
    else if (strstr("TITLE", "Prime")) { int ok = a > 1; for (long long p = 2; p * p <= a; p++) if (a % p == 0) ok = 0; printf("%s\n", ok ? "Prime" : "Not Prime"); }
    else if (strstr("TITLE", "GCD") || strstr("TITLE", "Greatest")) { while (b) { long long r = a % b; a = b; b = r; } printf("%lld\n", llabs(a)); }
    else if (strstr("TITLE", "LCM") || strstr("TITLE", "Least")) { long long x = a, y = b; while (y) { long long r = x % y; x = y; y = r; } printf("%lld\n", llabs(a / x * b)); }
    else if (strstr("TITLE", "Modular") || strstr("TITLE", "Modulo")) printf("%lld\n", ((a % m) + (b % m) + m) % m);
    else { long long s = 0, x = llabs(a); if (!x) s = 0; while (x) { s += x % 10; x /= 10; } printf("%lld\n", s); }

    return 0;
}
