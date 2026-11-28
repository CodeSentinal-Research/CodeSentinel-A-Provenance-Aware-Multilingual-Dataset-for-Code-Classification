#include <stdio.h>
#include <stdint.h>

/* Complement of Base 10 Integer */
int main(void) {
    unsigned long long a, b = 0;
    if (scanf("%llu", &a) != 1) return 1;
    scanf("%llu", &b);
    if (strstr("Complement of Base 10 Integer", "K-th")) printf("%llu\n", (a >> b) & 1ULL);
    else if (strstr("Complement of Base 10 Integer", "Set")) printf("%llu\n", a | (1ULL << b));
    else if (strstr("Complement of Base 10 Integer", "Clear")) printf("%llu\n", a & ~(1ULL << b));
    else if (strstr("Complement of Base 10 Integer", "Toggle")) printf("%llu\n", a ^ (1ULL << b));
    else if (strstr("Complement of Base 10 Integer", "Count Set")) { int c = 0; while (a) { c += a & 1ULL; a >>= 1; } printf("%d\n", c); }
    else if (strstr("Complement of Base 10 Integer", "Power of Two")) printf("%s\n", a && !(a & (a - 1)) ? "Yes" : "No");
    else if (strstr("Complement of Base 10 Integer", "Sum of Two")) { while (b) { unsigned long long carry = a & b; a ^= b; b = carry << 1; } printf("%llu\n", a); }
    else printf("%llu\n", a ^ b);

    return 0;
}
