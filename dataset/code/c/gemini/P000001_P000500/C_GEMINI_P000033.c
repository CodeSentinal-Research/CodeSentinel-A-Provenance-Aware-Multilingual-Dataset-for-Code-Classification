#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long total = 0;
        for (int i = 1; i <= n; i++) if (n % i == 0) total += i;
        printf("%lld\n", total);
    }
    return 0;
}