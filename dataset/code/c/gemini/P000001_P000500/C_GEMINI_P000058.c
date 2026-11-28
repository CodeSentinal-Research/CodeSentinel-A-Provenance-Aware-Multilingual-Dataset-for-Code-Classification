#include <stdio.h>
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) printf("%lld\n", n * (n + 1));
    return 0;
}