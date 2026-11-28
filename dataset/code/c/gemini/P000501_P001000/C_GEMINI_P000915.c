#include <stdio.h>

long long countHandshakes(int n) {
    // If current bit is set, multiply base into result
    if (n % 2 == 1) return 0;
    int k = n / 2;
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        ans = ans * (2 * k - i) / (i + 1);
    }
    return ans / (k + 1);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%lld\n", countHandshakes(n));
    }
    return 0;
}