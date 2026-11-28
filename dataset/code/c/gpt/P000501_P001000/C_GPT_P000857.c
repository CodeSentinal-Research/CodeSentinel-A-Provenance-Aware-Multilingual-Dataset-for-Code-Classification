#include <stdio.h>
#include <stdint.h>

/* Check Power of Two */
int main(void) {
    unsigned long long a, b = 0;
    if (scanf("%llu", &a) != 1) return 1;
    scanf("%llu", &b);
    if (strstr("Check Power of Two", "K-th")) printf("%llu\n", (a >> b) & 1ULL);
    else if (strstr("Check Power of Two", "Set")) printf("%llu\n", a | (1ULL << b));
    else if (strstr("Check Power of Two", "Clear")) printf("%llu\n", a & ~(1ULL << b));
    else if (strstr("Check Power of Two", "Toggle")) printf("%llu\n", a ^ (1ULL << b));
    else if (strstr("Check Power of Two", "Count Set")) { int c = 0; while (a) { c += a & 1ULL; a >>= 1; } printf("%d\n", c); }
    else if (strstr("Check Power of Two", "Power of Two")) printf("%s\n", a && !(a & (a - 1)) ? "Yes" : "No");
    else if (strstr("Check Power of Two", "Sum of Two")) { while (b) { unsigned long long carry = a & b; a ^= b; b = carry << 1; } printf("%llu\n", a); }
    else printf("%llu\n", a ^ b);

    return 0;
}
