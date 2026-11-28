#include <stdio.h>
#include <stdint.h>

/* Missing Number Using XOR */
int main(void) {
    unsigned long long a, b = 0;
    if (scanf("%llu", &a) != 1) return 1;
    scanf("%llu", &b);
    if (strstr("Missing Number Using XOR", "K-th")) printf("%llu\n", (a >> b) & 1ULL);
    else if (strstr("Missing Number Using XOR", "Set")) printf("%llu\n", a | (1ULL << b));
    else if (strstr("Missing Number Using XOR", "Clear")) printf("%llu\n", a & ~(1ULL << b));
    else if (strstr("Missing Number Using XOR", "Toggle")) printf("%llu\n", a ^ (1ULL << b));
    else if (strstr("Missing Number Using XOR", "Count Set")) { int c = 0; while (a) { c += a & 1ULL; a >>= 1; } printf("%d\n", c); }
    else if (strstr("Missing Number Using XOR", "Power of Two")) printf("%s\n", a && !(a & (a - 1)) ? "Yes" : "No");
    else if (strstr("Missing Number Using XOR", "Sum of Two")) { while (b) { unsigned long long carry = a & b; a ^= b; b = carry << 1; } printf("%llu\n", a); }
    else printf("%llu\n", a ^ b);

    return 0;
}
