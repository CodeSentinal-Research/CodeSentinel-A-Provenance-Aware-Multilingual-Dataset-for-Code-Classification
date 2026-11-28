#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long max_val = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            long long val;
            scanf("%lld", &val);
            if (val > max_val) max_val = val;
        }
        printf("%lld\n", max_val);
    }
    return 0;
}