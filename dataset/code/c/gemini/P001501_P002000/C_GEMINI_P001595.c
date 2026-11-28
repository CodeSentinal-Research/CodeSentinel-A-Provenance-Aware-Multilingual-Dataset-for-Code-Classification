#include <stdio.h>

int main() {
    int n, l, r;
    if (scanf("%d %d %d", &n, &l, &r) == 3) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (i >= l && i <= r) sum += x;
        }
        printf("%lld\n", sum);
    }
    return 0;
}