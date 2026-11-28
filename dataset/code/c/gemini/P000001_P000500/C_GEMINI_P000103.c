#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long val;
            scanf("%lld", &val);
            total += val;
        }
        printf("%lld\n", total);
    }
    return 0;
}