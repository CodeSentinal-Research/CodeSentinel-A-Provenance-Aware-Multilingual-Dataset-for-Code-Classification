#include <stdio.h>

int main() {
    long long n, s = 0;
    scanf("%lld", &n);
    while ((s + 1) * (s + 1) <= n) s++;
    printf("%lld\n", s);
    return 0;
}
