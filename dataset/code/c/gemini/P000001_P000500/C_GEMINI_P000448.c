#include <stdio.h>
int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        long long l = 0, r = n, ans = 0;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            if (mid * mid <= n) { ans = mid; l = mid + 1; }
            else r = mid - 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}