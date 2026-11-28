#include <stdio.h>
int main() {
    long long a, b, m; scanf("%lld%lld%lld", &a, &b, &m);
    printf("%lld\n", ((a % m) * (b % m)) % m);
    return 0;
}
