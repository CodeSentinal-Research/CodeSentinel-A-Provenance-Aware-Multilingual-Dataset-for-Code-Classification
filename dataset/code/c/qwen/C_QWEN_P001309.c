#include <stdio.h>

int main() {
    long long s, n, m;
    scanf("%lld%lld%lld", &s, &n, &m);
    long long total = s * m;
    long long days = (total + n - 1) / n;
    printf("%lld\n", days);
    return 0;
}
