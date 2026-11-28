#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long min_val = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long val;
            scanf("%lld", &val);
            if (val < min_val) min_val = val;
        }
        printf("%lld\n", min_val);
    }
    return 0;
}