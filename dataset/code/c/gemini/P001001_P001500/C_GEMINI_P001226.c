#include <stdio.h>

#define MOD 1000000007LL

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n <= 2) {
            printf("%d\n", n);
            return 0;
        }
        long long a = 1, b = 2;
        for (long long i = 3; i <= n; i++) {
            long long c = (b + (i - 1) * a) % MOD;
            a = b;
            b = c;
        }
        printf("%lld\n", b);
    }
    return 0;
}