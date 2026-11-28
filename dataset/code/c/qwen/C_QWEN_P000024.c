#include <stdio.h>

int main() {
    long long n, s = 0;
    scanf("%lld", &n);
    if (n == 0) s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    printf("%lld\n", s);
    return 0;
}
