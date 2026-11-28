#include <stdio.h>

long long starsAndBars(int n, int k) {
    int total = n + k - 1;
    int r = k - 1;
    if (r < 0 || r > total) return 0;
    if (r > total - r) r = total - r;
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (total - i + 1) / i;
    }
    return ans;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        printf("%lld\n", starsAndBars(n, k));
    }
    return 0;
}