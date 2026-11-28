#include <stdio.h>
int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        printf("%s\n", a % b == 0 ? "Divisible" : "Not Divisible");
    }
    return 0;
}