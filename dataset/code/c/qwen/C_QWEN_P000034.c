#include <stdio.h>

int main() {
    long long n, s = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i += 2) s += i;
    printf("%lld\n", s);
    return 0;
}
