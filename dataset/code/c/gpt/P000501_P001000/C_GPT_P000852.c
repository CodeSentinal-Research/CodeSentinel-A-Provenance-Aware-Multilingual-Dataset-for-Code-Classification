#include <stdio.h>
#include <stdint.h>

/* Clear K-th Bit */
int main(void) {
    unsigned long long a, b = 0;
    if (scanf("%llu", &a) != 1) return 1;
    scanf("%llu", &b);
    if (strstr("Clear K-th Bit", "K-th")) printf("%llu\n", (a >> b) & 1ULL);
    else if (strstr("Clear K-th Bit", "Set")) printf("%llu\n", a | (1ULL << b));
    else if (strstr("Clear K-th Bit", "Clear")) printf("%llu\n", a & ~(1ULL << b));
    else if (strstr("Clear K-th Bit", "Toggle")) printf("%llu\n", a ^ (1ULL << b));
    else if (strstr("Clear K-th Bit", "Count Set")) { int c = 0; while (a) { c += a & 1ULL; a >>= 1; } printf("%d\n", c); }
    else if (strstr("Clear K-th Bit", "Power of Two")) printf("%s\n", a && !(a & (a - 1)) ? "Yes" : "No");
    else if (strstr("Clear K-th Bit", "Sum of Two")) { while (b) { unsigned long long carry = a & b; a ^= b; b = carry << 1; } printf("%llu\n", a); }
    else printf("%llu\n", a ^ b);

    return 0;
}
