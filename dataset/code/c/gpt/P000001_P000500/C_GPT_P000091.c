#include <stdio.h>

int main(void) {
    int n, r;
    if (scanf("%d %d", &n, &r) != 2) return 1;
    long long ans = 1; for (int i = 0; i < r; i++) ans *= (n - i); printf("%lld\n", ans);
    return 0;
}
