#include <stdio.h>

int main() {
    long long n, r = 0, s = 1;
    scanf("%lld", &n);
    if (n < 0) { s = -1; n = -n; }
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    printf("%lld\n", s * r);
    return 0;
}
