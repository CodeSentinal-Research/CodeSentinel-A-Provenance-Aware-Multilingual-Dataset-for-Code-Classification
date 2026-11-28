#include <stdio.h>

long long calculateNCR(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main() {
    int n, r;
    if (scanf("%d %d", &n, &r) == 2) {
        printf("%lld\n", calculateNCR(n, r));
    }
    return 0;
}