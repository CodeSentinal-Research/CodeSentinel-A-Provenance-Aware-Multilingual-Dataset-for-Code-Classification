#include <stdio.h>

#define MOD 1000000007LL

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 1) {
            printf("2\n");
            return 0;
        }
        long long a = 1, b = 2;
        for (int i = 2; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
        }
        printf("%lld\n", b);
    }
    return 0;
}