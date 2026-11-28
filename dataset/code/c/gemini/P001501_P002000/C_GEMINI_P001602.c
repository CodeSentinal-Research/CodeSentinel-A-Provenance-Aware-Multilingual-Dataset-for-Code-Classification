#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long cur = 0, maxAbs = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            cur += x;
            maxAbs = MAX(maxAbs, llabs(cur));
        }
        printf("%lld\n", maxAbs);
    }
    return 0;
}