#include <stdio.h>

long long circularArrangements(int n) {
    if (n <= 1) return 1;
    long long ans = 1;
    for (int i = 1; i < n; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%lld\n", circularArrangements(n));
    }
    return 0;
}