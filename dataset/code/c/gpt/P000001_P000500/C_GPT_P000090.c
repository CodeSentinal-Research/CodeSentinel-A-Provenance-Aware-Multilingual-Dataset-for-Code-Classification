#include <stdio.h>

int main(void) {
    int n, r;
    if (scanf("%d %d", &n, &r) != 2) return 1;
    long long ans = 1; if (r > n - r) r = n - r; for (int i = 1; i <= r; i++) ans = ans * (n - r + i) / i; printf("%lld\n", ans);
    return 0;
}
