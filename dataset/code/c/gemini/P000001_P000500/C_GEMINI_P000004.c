#include <stdio.h>
#include <limits.h>

int main(void) {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        if (b == 0) {
            return 0; // Avoid division by zero
        }
        if (a == LLONG_MIN && b == -1) {
            // Handle overflow case: -9223372036854775808 / -1 = 9223372036854775808
            printf("9223372036854775808\n");
        } else {
            printf("%lld\n", a / b);
        }
    }
    return 0;
}