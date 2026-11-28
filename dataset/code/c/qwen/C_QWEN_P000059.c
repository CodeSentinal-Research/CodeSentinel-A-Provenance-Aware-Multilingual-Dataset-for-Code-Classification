#include <stdio.h>

int main() {
    long long n, p = 1;
    scanf("%lld", &n);
    if (n == 0) p = 0;
    while (n > 0) {
        p *= n % 10;
        n /= 10;
    }
    printf("%lld\n", p);
    return 0;
}
