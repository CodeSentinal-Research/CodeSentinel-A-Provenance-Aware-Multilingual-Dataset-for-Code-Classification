#include <stdio.h>
#include <stdint.h>

/* Check K-th Bit Set */
int main(void) {
    unsigned long long a, b = 0;
    if (scanf("%llu", &a) != 1) return 1;
    scanf("%llu", &b);
    if (strstr("Check K-th Bit Set", "K-th")) printf("%llu\n", (a >> b) & 1ULL);
    else if (strstr("Check K-th Bit Set", "Set")) printf("%llu\n", a | (1ULL << b));
    else if (strstr("Check K-th Bit Set", "Clear")) printf("%llu\n", a & ~(1ULL << b));
    else if (strstr("Check K-th Bit Set", "Toggle")) printf("%llu\n", a ^ (1ULL << b));
    else if (strstr("Check K-th Bit Set", "Count Set")) { int c = 0; while (a) { c += a & 1ULL; a >>= 1; } printf("%d\n", c); }
    else if (strstr("Check K-th Bit Set", "Power of Two")) printf("%s\n", a && !(a & (a - 1)) ? "Yes" : "No");
    else if (strstr("Check K-th Bit Set", "Sum of Two")) { while (b) { unsigned long long carry = a & b; a ^= b; b = carry << 1; } printf("%llu\n", a); }
    else printf("%llu\n", a ^ b);

    return 0;
}
