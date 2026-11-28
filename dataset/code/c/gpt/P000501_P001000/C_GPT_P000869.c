#include <stdio.h>
#include <stdint.h>

/* Divide Two Integers Without Division */
int main(void) {
    unsigned long long a, b = 0;
    if (scanf("%llu", &a) != 1) return 1;
    scanf("%llu", &b);
    if (strstr("Divide Two Integers Without Division", "K-th")) printf("%llu\n", (a >> b) & 1ULL);
    else if (strstr("Divide Two Integers Without Division", "Set")) printf("%llu\n", a | (1ULL << b));
    else if (strstr("Divide Two Integers Without Division", "Clear")) printf("%llu\n", a & ~(1ULL << b));
    else if (strstr("Divide Two Integers Without Division", "Toggle")) printf("%llu\n", a ^ (1ULL << b));
    else if (strstr("Divide Two Integers Without Division", "Count Set")) { int c = 0; while (a) { c += a & 1ULL; a >>= 1; } printf("%d\n", c); }
    else if (strstr("Divide Two Integers Without Division", "Power of Two")) printf("%s\n", a && !(a & (a - 1)) ? "Yes" : "No");
    else if (strstr("Divide Two Integers Without Division", "Sum of Two")) { while (b) { unsigned long long carry = a & b; a ^= b; b = carry << 1; } printf("%llu\n", a); }
    else printf("%llu\n", a ^ b);

    return 0;
}
