#include <stdio.h>

#define MOD 1000000007LL

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 1) {
            printf("0\n");
            return 0;
        }
        if (n == 2) {
            printf("1\n");
            return 0;
        }
        long long a = 0, b = 1;
        for (long long i = 3; i <= n; i++) {
            long long c = ((i - 1) * (a + b)) % MOD;
            a = b;
            b = c;
        }
        printf("%lld\n", b);
    }
    return 0;
}