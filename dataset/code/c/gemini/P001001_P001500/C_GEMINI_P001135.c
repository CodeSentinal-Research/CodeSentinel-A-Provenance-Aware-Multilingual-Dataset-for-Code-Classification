#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        long long inc = 0, exc = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            scanf("%lld", &x);
            long long newInc = exc + x;
            long long newExc = MAX(inc, exc);
            inc = newInc;
            exc = newExc;
        }
        printf("%lld\n", MAX(inc, exc));
    }
    return 0;
}