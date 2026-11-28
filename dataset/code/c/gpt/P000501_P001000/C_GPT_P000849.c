#include <stdio.h>
#include <stdint.h>

/* Check Even or Odd Using Bitwise Operator */
int main(void) {
    unsigned long long a, b = 0;
    if (scanf("%llu", &a) != 1) return 1;
    scanf("%llu", &b);
    if (strstr("Check Even or Odd Using Bitwise Operator", "K-th")) printf("%llu\n", (a >> b) & 1ULL);
    else if (strstr("Check Even or Odd Using Bitwise Operator", "Set")) printf("%llu\n", a | (1ULL << b));
    else if (strstr("Check Even or Odd Using Bitwise Operator", "Clear")) printf("%llu\n", a & ~(1ULL << b));
    else if (strstr("Check Even or Odd Using Bitwise Operator", "Toggle")) printf("%llu\n", a ^ (1ULL << b));
    else if (strstr("Check Even or Odd Using Bitwise Operator", "Count Set")) { int c = 0; while (a) { c += a & 1ULL; a >>= 1; } printf("%d\n", c); }
    else if (strstr("Check Even or Odd Using Bitwise Operator", "Power of Two")) printf("%s\n", a && !(a & (a - 1)) ? "Yes" : "No");
    else if (strstr("Check Even or Odd Using Bitwise Operator", "Sum of Two")) { while (b) { unsigned long long carry = a & b; a ^= b; b = carry << 1; } printf("%llu\n", a); }
    else printf("%llu\n", a ^ b);

    return 0;
}
