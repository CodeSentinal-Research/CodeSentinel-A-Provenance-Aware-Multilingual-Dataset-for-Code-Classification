#include <stdio.h>

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    long long ans = 1;
    for (int i = 0; i < r; i++) {
        ans *= (n - i);
    }
    return ans;
}

int main() {
    int n, r;
    if (scanf("%d %d", &n, &r) == 2) {
        printf("%lld\n", nPr(n, r));
    }
    return 0;
}