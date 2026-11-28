#include <stdio.h>

long long countDerangements(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    long long prev2 = 1, prev1 = 0;
    for (int i = 2; i <= n; i++) {
        long long curr = (i - 1) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%lld\n", countDerangements(n));
    }
    return 0;
}